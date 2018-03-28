//
//  ListBaseQueue.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 28..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "ListBaseQueue.h"

// 큐를 초기화 front와 rear가 NULL을 가리키게
void QueueInit(Queue * pq)
{
    pq->front = NULL;
    pq->rear = NULL;
}

// front가 NULL을 가리키면 큐가 빈 것이다
int QIsEmpty(Queue * pq)
{
    if(pq->front == NULL)
        return TRUE;
    else
        return FALSE;
}

// 큐에 데이터를 삽입하는 함수
void Enqueue(Queue * pq, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    
    // newNode의 next가 NULL을 가리키게 하지 않으면
    // 이후에 Dequeue를 반복하여 큐가 텅텅 비게 되었음에도
    // QIsEmpty 함수를 호출하면 FALSE로 나올 수 있다.
    newNode->next = NULL;
    newNode->data = data;
    
    // 큐가 비었을 때는 첫 노드 삽입시에 front와 rear 모두
    // newNode를 가리키게 해야한다
    if(QIsEmpty(pq))
    {
        pq->front = newNode;
        pq->rear = newNode;
    }
    // 큐가 비어있지 않을 때는 rear만 한 칸 이동하면서 노드를
    // 삽입하면 된다
    else
    {
        pq->rear->next = newNode;
        pq->rear = newNode;
    }
}

// 큐에 있는 먼저 들어간 데이터를 삭제하고 반환하는 함수
Data Dequeue(Queue * pq)
{
    Node * delNode;
    Data retData;
    
    if(QIsEmpty(pq))
    {
        printf("Queue is Empty !! \n");
        exit(-1);
    }
    
    delNode = pq->front;
    retData = delNode->data;
    
    // front를 front가 가리키고 있는 다음 노드를
    // 새롭게 가리키도록
    pq->front = pq->front->next;
    
    free(delNode);
    return retData;
}

// 다음에 큐에서 나올 데이터가 무엇인지 반환 해주는 함수
Data QPeek(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue is Empty !! \n");
        exit(-1);
    }
    
    return pq->front->data;
}
