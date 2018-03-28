//
//  ListBaseQueue.h
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 28..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#ifndef ListBaseQueue_h
#define ListBaseQueue_h

#define TRUE        1
#define FALSE       0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node * next;
} Node;

typedef struct _lQueue
{
    Node * front;
    Node * rear;
} LQueue;

typedef LQueue Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);

void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif /* ListBaseQueue_h */
