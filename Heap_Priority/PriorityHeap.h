//
//  PriorityHeap.h
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 4. 8..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#ifndef PriorityHeap_h
#define PriorityHeap_h

#define TRUE        1
#define FALSE       0

#define HEAP_LEN    100

typedef char HData;
typedef int Priority;


// 힙의 원소 구조체는 우선순위를 나타내는 pr 과
// 데이터를 저장하는 data로 구성
typedef struct _heapElem
{
    Priority pr;    // 값이 작을수록 높은 우선순위
    HData data;
} HeapElem;

typedef struct _heap
{
    int numOfData;
    HeapElem heapArr[HEAP_LEN];
} Heap;

void HeapInit(Heap * ph);
int HIsEmpty(Heap * ph);

void HInsert(Heap * ph, HData data, Priority pr);
HData HDelete(Heap * ph);

#endif /* PriorityHeap_h */
