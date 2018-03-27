//
//  InfixToPostfix.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 27..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "ListBaseStack.h"

// 중위 표기식을 후위 표기식으로 변환하는데 필요한 함수
// void ConvToRPNExp(char exp[])

// 연산자 우선순위를 정해주는 함수
int GetOpPrec(char op)
{
    switch (op)
    {
        case '*':
        case '/':
            return 5;
        case '+':
        case '-':
            return 3;
        case '(':
            return 1;
    }
    return -1;
}

// 연산자 두개 중에 어느 연산자가 더 우선순위가 높은지 결과를 리턴하는 함수
int WhoPrecOp(char op1, char op2)
{
    int op1Prec = GetOpPrec(op1);
    int op2Prec = GetOpPrec(op2);
    
    if(op1Prec > op2Prec)
        return 1;
    else if(op1Prec < op2Prec)
        return -1;
    else
        return 0;
}

// 중위 표기식을 후위 표기식으로 변환하는 함수
void ConvToRPNExp(char exp[])
{
    Stack stack;
    int expLen = strlen(exp);
    // 중위 표기식이 있는 배열의 크기만큼 새로운 공간을 할당
    char * convExp = (char*)malloc(expLen+1);
    
    int idx = 0;
    char tok, popOp;
    
    // convExp 공간을 0으로 초기화
    memset(convExp, 0, sizeof(char)*expLen+1);
    StackInit(&stack);
    
    for(int i=0; i<expLen; i++)
    {
        tok = exp[i];
        
        // 피연산자(숫자)이면 바로 새로운 후위 표기식 공간(convExp에 삽입)
        if(isdigit(tok))
        {
            convExp[idx++] = tok;
        }
        // 연산자는 기본적으로 스택에 삽입
        else
        {
            switch (tok)
            {
                // ( 이면 바로 스택에 push
                case '(':
                    SPush(&stack, tok);
                    break;
                
                // ) 이면 (가 나올 때 까지 스택을 pop하고 반환되는 값을
                // convExp에 삽입
                case ')':
                    while(1)
                    {
                        popOp = SPop(&stack);
                        if(popOp == '(')
                            break;
                        convExp[idx++] = popOp;
                    }
                    break;
                    
                // 아래의 연산자가 나왔을 때, 스택이 비어있지 않고 스택의 top(가장 위에 있는 연산자)이
                // 새로 들어가는(tok) 연산자보다 우선순위가 높으면 스택을 pop한 후에 convExp에 삽입
                case '+': case '-':
                case '*': case '/':
                    while(!SIsEmpty(&stack) && WhoPrecOp(SPeek(&stack), tok) >= 0)
                        convExp[idx++] = SPop(&stack);
                    SPush(&stack, tok);
                    break;
            }
        }
    }
    
    // 위의 과정을 다 끝낸 상태에서 스택에 남은 연산자들을 pop한 후
    // convExp에 삽입
    while(!SIsEmpty(&stack))
        convExp[idx++] = SPop(&stack);
    
    // exp에다 convExp를 복사
    strcpy(exp, convExp);
    // convExp는 활용 가치가 없어졌기 때문에 메모리 해제
    free(convExp);
}
