//
//  PostCalculator.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 28..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"

// 후위 표기식을 계산해서 결과값을 리턴하는 함수
int EvalRPNExp(char exp[])
{
    Stack stack;
    
    int expLen = strlen(exp);
    
    char tok, op1, op2;
    
    StackInit(&stack);
    
    for(int i=0; i<expLen; i++)
    {
        tok = exp[i];
        
        // 후위표기식 전체를 반복문으로 돌리면서
        // 숫자가 나오면 스택에 push
        if(isdigit(tok))
        {
            SPush(&stack, tok - '0');
        }
        else
        {
            // 연산자가 나오면 스택에서 피연산자 두개를 가져옴
            // 피연산자 위치로 인해 연산 결과가 달라질 수 있으므로
            // 최근에 들어간 피연산자를 2번째 피연산자로 둔다
            op2 = SPop(&stack);
            op1 = SPop(&stack);
            
            switch (tok) {
                case '+':
                    SPush(&stack, op1 + op2);
                    break;
                
                case '-':
                    SPush(&stack, op1 - op2);
                    break;
                
                case '*':
                    SPush(&stack, op1 * op2);
                    break;
                
                case '/':
                    SPush(&stack, op1 / op2);
                    break;
            }
        }
    }
    return SPop(&stack);
}
