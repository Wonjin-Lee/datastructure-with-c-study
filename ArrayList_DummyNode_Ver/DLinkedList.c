//
//  DLinkedList.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 13..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "DLinkedList.h"

// 리스트 구조체 변수를 초기화
void ListInit(List * plist)
{
    // dummy를 만들기위해 동적 할당.
    plist->head = (Node*)malloc(sizeof(Node));
    plist->head->next = NULL;
    plist->comp = NULL;
    plist->numOfData = 0;
}

// 정렬 기준이 없을 때 데이터를 삽입하는 함수.
void FInsert(List * plist, LData data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    // 새로운 노드의 다음 노드의 주소를 헤드가 가리키고 있는 노드로.
    newNode->next = plist->head->next;
    // 새로운 노드를 헤드가 가리키도록.
    plist->head->next = newNode;
    
    (plist->numOfData)++;
}

// 정렬 기준이 있을 때 데이터를 기준에 맞게 삽입하는 함수.
void SInsert(List * plist, LData data)
{
    
}

// comp의 유무에 따라 위의 삽입 함수 두 개로 나뉨.
void LInsert(List * plist, LData data)
{
    if(plist->comp == NULL)
        FInsert(plist, data);
    else
        SInsert(plist, data);
}

// 연결 리스트를 조회할 때 먼저 수행하는 함수.
int LFirst(List * plist, LData * pdata)
{
    if(plist->head->next == NULL)
        return FALSE;
    
    // before이 더미를 가리키게 하고 cur이 더미 다음에 있는 노드를 가리키게.
    plist->before = plist->head;
    plist->cur = plist->head->next;
    
    *pdata = plist->cur->data;
    return TRUE;
}

// LFirst 이후에 조회를 할 때 사용하는 함수.
int LNext(List * plist, LData * pdata)
{
    if(plist->cur->next == NULL)
        return FALSE;
    
    // before과 cur이 한칸씩 앞으로 가도록.
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    
    *pdata = plist->cur->data;
    return TRUE;
}

// LFirst나 LNext를 통해 조회된 노드를 삭제하는 함수.
LData LRemove(List * plist)
{
    // 노드를 삭제(free)하기 위해 주소값을 저장.
    Node * rpos = plist->cur;
    
    // 삭제되는 노드의 값을 리턴해주기 위해.
    LData rdata = rpos->data;
    
    // 삭제되는 노드의 왼쪽 노드를 삭제되는 노드의 다음 노드에 연결.
    plist->before->next = plist->cur->next;
    
    // cur을 이전 노드를 가리키게 한다.
    plist->cur = plist->before;
    
    // 노드를 삭제.
    free(rpos);
    (plist->numOfData)--;
    
    return rdata;
}

// 연결리스트의 원소의 수를 리턴.
int LCount(List * plist)
{
    return plist->numOfData;
}

void SetSortRule(List * plist, int (*comp)(LData d1, LData d2))
{
     
}
