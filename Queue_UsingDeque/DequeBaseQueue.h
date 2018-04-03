//
//  DequeBaseQueue.h
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 30..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#ifndef DequeBaseQueue_h
#define DequeBaseQueue_h

#include "Deque.h"

typedef Deque Queue;

void QueueInit(Queue * pq);
int QIsEmpty(Queue * pq);
void Enqueue(Queue * pq, Data data);
Data Dequeue(Queue * pq);
Data QPeek(Queue * pq);

#endif /* DequeBaseQueue_h */
