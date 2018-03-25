//
//  ArrayBaseStack.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 23..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "ArrayBaseStack.h"

// 배열 기반의 스택

// 스택 구조체 변수를 초기화 하는 함수
void StackInit(Stack * pstack)
{
    // top을 가리키는 멤버를 -1로 초기화 시킨다
    pstack->topIndex = -1;
}

// 스택이 비어있는지 확인하는 함수
int SIsEmpty(Stack * pstack)
{
    if(pstack->topIndex == -1)
        return TRUE;
    else
        return FALSE;
}

// 스택의 topIndex를 1증가시키고 그 자리에 데이터를 삽입
void SPush(Stack * pstack, Data data)
{
    pstack->topIndex += 1;
    pstack->stackArr[pstack->topIndex] = data;
}

// 스택의 top에 있는 원소를 삭제하고 그 원소를 반환
Data SPop(Stack * pstack)
{
    int rIdx;
    
    if(SIsEmpty(pstack))
    {
        printf("Stack Empty !");
        exit(-1);
    }
    rIdx = pstack->topIndex;
    pstack->topIndex -= 1;
    
    return pstack->stackArr[rIdx];
}

// 스택의 top에 있는 원소를 삭제하지 않고 반환만 해줌
Data SPeek(Stack * pstack)
{
    if(SIsEmpty(pstack))
    {
        printf("Stack Empty !");
        exit(-1);
    }
    
    return pstack->stackArr[pstack->topIndex];
}
