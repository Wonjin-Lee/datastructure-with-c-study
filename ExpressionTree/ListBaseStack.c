//
//  ListBaseStack.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 26..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "ListBaseStack.h"


// 스택 초기화
void StackInit(Stack * pstack)
{
    // head가 NULL을 가리키게
    pstack->head = NULL;
}

// 스택이 비어있는지 확인하는 함수
int SIsEmpty(Stack * pstack)
{
    // head가 NULL을 가리키면 스택이 비어있으므로 TRUE(1)을 리턴
    if(pstack->head == NULL)
        return TRUE;
    else
        return FALSE;
}

// 스택의 head에 새로운 노드를 삽입하는 함수
void SPush(Stack * pstack, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    
    newNode->data = data;
    
    // 새로운 노드의 다음 노드는 이전에 head가 가리키던 노드가 되어야 한다.
    newNode->next = pstack->head;
    
    // head는 새로운 노드를 가리키게끔
    pstack->head = newNode;
}

// 후입선출(LIFO)이므로 가장 최근에 들어간(head가 가리키고 있는) 원소를 삭제시키고 반환
Data SPop(Stack * pstack)
{
    Data rdata;
    Node * rnode;
    
    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }
    
    // 원소 반환을 위해 rdata에 반환할 데이터를 저장
    rdata = pstack->head->data;
    
    // head가 가리키고 있는 노드(삭제할 노드)를 가리키게 하여
    // 이후에 free로 메모리를 해제시킴
    rnode = pstack->head;
    
    // head가 삭제할 노드의 next를 가리키게 한 뒤에 노드 삭제
    pstack->head = pstack->head->next;
    free(rnode);
    
    return rdata;
}

// SPop처럼 head가 가리키고 있는(가장 위쪽)노드의 데이터를 반환하지만
// 삭제는 하지 않음
Data SPeek(Stack * pstack)
{
    if(SIsEmpty(pstack)) {
        printf("Stack Memory Error!");
        exit(-1);
    }
    
    return pstack->head->data;
}

