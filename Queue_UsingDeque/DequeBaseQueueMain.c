//
//  DequeBaseQueueMain.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 30..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include "DequeBaseQueue.h"

int main(void)
{
    Queue q;
    QueueInit(&q);
    
    Enqueue(&q, 1);
    Enqueue(&q, 2);
    Enqueue(&q, 3);
    Enqueue(&q, 4);
    Enqueue(&q, 5);
    
    while(!QIsEmpty(&q))
    {
        printf("%d ", Dequeue(&q));
    }
    
    printf("\n");
    
    return 0;
}
