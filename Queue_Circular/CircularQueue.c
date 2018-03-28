//
//  CircularQueue.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 28..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "CircularQueue.h"

// 큐의 front와 rear가 같은 곳을 가리키도록 초기화
// 같은 곳을 가리킨다는 것은 큐가 비어있다는 뜻
void QueueInit(Queue * pq)
{
    pq->front = 0;
    pq->rear = 0;
}

// 큐의 front와 rear가 같다면 큐가 비어있다는 것
int QIsEmpty(Queue * pq)
{
    if(pq->front == pq->rear)
        return TRUE;
    else
        return FALSE;
}

// front나 rear의 다음 인덱스를 반환해주는 함수
// front나 rear의 다음 인덱스가 배열의 끝이면
// 다음 인덱스로 0을 반환(원형 큐)
int NextPosIdx(int pos)
{
    if(pos == QUE_LEN - 1)
        return 0;
    else
        return pos+1;
}

// 큐에 원소를 삽입하는 함수
void Enqueue(Queue * pq, Data data)
{
    // rear의 다음 인덱스가 front와 같다면
    // 큐가 가득 찬 상태임
    if(NextPosIdx(pq->rear) == pq->front)
    {
        printf("Queue is Full ! \n");
        exit(-1);
    }
    
    // 큐가 가득찬게 아니라면
    // rear를 한칸 이동시키고 그 자리에 원소 삽입
    pq->rear = NextPosIdx(pq->rear);
    pq->queArr[pq->rear] = data;
}

// 큐에 원소를 삭제하는 함수
// 여기서는 삭제를 하지 않고 다음번에 다른 원소가 덮어씌우도록
Data Dequeue(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue is Empty ! \n");
        exit(-1);
    }
    
    // front를 한 칸 이동 시키고 그 자리에 있는 원소를 반환
    // 언젠간 rear가 그 자리에 다른 원소를 덮어 씌울 것이다
    pq->front = NextPosIdx(pq->front);
    return pq->queArr[pq->front];
}

// 다음번에 나올 차례인 원소를 반환하는 함수
Data QPeek(Queue * pq)
{
    if(QIsEmpty(pq))
    {
        printf("Queue is Empty ! \n");
        exit(-1);
    }
    
    return pq->queArr[NextPosIdx(pq->front)];
}
