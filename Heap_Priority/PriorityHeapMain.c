//
//  PriorityHeapMain.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 4. 8..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include "PriorityHeap.h"

int main(void)
{
    Heap heap;
    HeapInit(&heap);        // 힙의 초기화
    
    HInsert(&heap, 'A', 1);     // A를 1순위로 저장
    HInsert(&heap, 'B', 2);     // B를 2순위로 저장
    HInsert(&heap, 'C', 3);     // C를 3순위로 저장
    printf("%c \n", HDelete(&heap));
    
    HInsert(&heap, 'A', 1);     // A를 한번 더 저장
    HInsert(&heap, 'B', 2);     // B를 한번 더 저장
    HInsert(&heap, 'C', 3);     // C를 한번 더 저장
    printf("%c \n", HDelete(&heap));
    
    while(!HIsEmpty(&heap))
        printf("%c \n", HDelete(&heap));
    
    return 0;
}
