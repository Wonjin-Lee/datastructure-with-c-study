//
//  Deque.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 28..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Deque.h"

// 덱을 초기화 하는 함수
void DequeInit(Deque * pdeq)
{
    pdeq->head = NULL;
    pdeq->tail = NULL;
}

// head를 기준으로한다
// head가 NULL이면 덱이 빈 것임
int DQIsEmpty(Deque * pdeq)
{
    if(pdeq->head == NULL)
        return TRUE;
    else
        return FALSE;
}

// 데이터를 앞에다가(head)에 삽입하는 함수
void DQAddFirst(Deque * pdeq, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    // head(앞)에 데이터를 삽입하는 것이기 때문에
    // 새로운 노드의 next가 기존에 head가 가리키고 있던 것을 가리키게
    // 덱이 비어있는 경우 newNode의 next는 NULL을 가지게 된다
    newNode->next = pdeq->head;
    
    // 덱이 비어있는 경우 tail이 newNode를 가리키게 해야한다
    if(DQIsEmpty(pdeq))
        pdeq->tail = newNode;
    else
        // 비어있는게 아니라면 기존에 head가 가리키고 있던 노드의 prev가
        // newNode를 가리키게끔
        pdeq->head->prev = newNode;
    
    newNode->prev = NULL;
    pdeq->head = newNode;
}

// DQAddFirst와 반대로 tail에 데이터를 삽입하는 함수
// 코드도 반대로이다.
void DQAddLast(Deque * pdeq, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    newNode->prev = pdeq->tail;
    
    if(DQIsEmpty(pdeq))
        pdeq->head = newNode;
    else
        pdeq->tail->next = newNode;
    
    newNode->next = NULL;
    pdeq->tail = newNode;
}

// head가 가리키는 노드를 삭제하는 함수(앞에서 데이터를 삭제)
Data DQRemoveFirst(Deque * pdeq)
{
    Node * rnode = pdeq->head;
    Data rdata;
    
    if(DQIsEmpty(pdeq))
    {
        printf("Deque is Empty");
        exit(-1);
    }
    
    rdata = pdeq->head->data;
    
    // head를 한칸 뒤에 있는 노드를 가리키게 한다
    pdeq->head = pdeq->head->next;
    free(rnode);
    
    
    // head가 head의 next를 가리키기 때문에 head는 null을 가리킨다
    // (마지막 노드의 next는 NULL이다)
    // 마지막 노드를 삭제한 경우에는 tail도 NULL을 가리키게 한다
    if(pdeq->head == NULL)
        //
        pdeq->tail = NULL;
    else
        // 마지막 노드를 삭제한게 아니라면 head가 가리키는 노드의 prev를
        // NULL로 한다
        pdeq->head->prev = NULL;
    
    return rdata;
}

// DQRemoveFirst와 반대로
Data DQRemoveLast(Deque * pdeq)
{
    Node * rnode = pdeq->tail;
    Data rdata;
    
    if(DQIsEmpty(pdeq))
    {
        printf("Deque is Empty");
        exit(-1);
    }
    
    rdata = pdeq->tail->data;
    
    pdeq->tail = pdeq->tail->prev;
    free(rnode);
    
    if(pdeq->tail->prev == NULL)
        pdeq->head = NULL;
    else
        pdeq->tail->next = NULL;
    
    return rdata;
}

// 노드를 삭제하지 않고 head가 가리키는 노드를 반환
Data DQGetFirst(Deque * pdeq)
{
    if(DQIsEmpty(pdeq))
    {
        printf("Deque is Empty");
        exit(-1);
    }
    
    return pdeq->head->data;
}

// 노드를 삭제하지 않고 tail이 가리키는 노드를 반환
Data DQGetLast(Deque * pdeq)
{
    if(DQIsEmpty(pdeq))
    {
        printf("Deque is Empty");
        exit(-1);
    }
    
    return pdeq->tail->data;
}
