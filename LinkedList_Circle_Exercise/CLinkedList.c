//
//  CLinkedList.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 14..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

// 원형 연결 리스트
#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

// 원형 연결 리스트 구조체 변수를 초기화 해주는 함수.
void ListInit(List * plist)
{
    plist->tail = NULL;
    plist->cur = NULL;
    plist->before = NULL;
    plist->numOfData = 0;
}

// 새로운 노드를 리스트의 head(앞부분)에 삽입하는 함수.
void LInsertFront(List * plist, Number number, Name name)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->number = number;
    newNode->name = name;
    
    if(plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {   // 노드들이 가리키는 방향을 새로 설정하는 명령.
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
    }
    (plist->numOfData)++;
}

// 새로운 노드를 리스트의 tail(뒷부분)에 삽입하는 함수.
void LInsert(List * plist, Number number, Name name)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->number = number;
    newNode->name = name;
    
    if(plist->tail == NULL)
    {
        plist->tail = newNode;
        newNode->next = newNode;
    }
    else
    {   // 노드들이 가리키는 방향을 새로 설정하는 명령.
        // 위의 함수와 다르게 tail이 새로운 노드를 가리키게 한다.
        newNode->next = plist->tail->next;
        plist->tail->next = newNode;
        plist->tail = newNode;
    }
    (plist->numOfData)++;
}

// 원형 연결 리스트를 탐색할 때 처음으로 호출해야 하는 함수.
int LFirst(List * plist, Number * pnumber, Name * pname)
{
    if(plist->tail == NULL)
        return FALSE;
    
    // before과 cur이 각각 꼬리와 그 다음에 있는 노드를 가리키게 한다.
    plist->before = plist->tail;
    plist->cur = plist->tail->next;
    
    *pnumber = plist->cur->number;
    *pname = plist->cur->name;
    return TRUE;
}

// 탐색시 LFirst이후에 호출하는 함수.
// 원형 연결 리스트이기 때문에 무한정 반복되면서 돌아간다.
int LNext(List * plist, Number * pnumber, Name * pname)
{
    if(plist->tail == NULL)
        return FALSE;
    
    plist->before = plist->cur;
    plist->cur = plist->cur->next;
    
    *pnumber = plist->cur->number;
    *pname = plist->cur->name;
    return TRUE;
}

// LFirst 또는 LNext함수로 인해 최근 조회된 노드를 삭제.
Name LRemove(List * plist)
{
    Node * rpos = plist->cur;
    Name rname = rpos->name;
    
    // 단순 연결 리스트와 달리 리스트에 cur이 tail이 가리키는 상황에서는
    // tail이 가리키는 방향을 새로 조정해 주어야 한다.
    if(rpos == plist->tail)
    {
        if(plist->tail == plist->tail->next)
            plist->tail = NULL;
        else
            plist->tail = plist->before;
    }
    
    plist->before->next = plist->cur->next;
    plist->cur = plist->before;
    
    free(rpos);
    (plist->numOfData)--;
    
    return rname;
}

// 원형 연결 리스트에 있는 노드의 개수를 리턴.
int LCount(List * plist)
{
    return plist->numOfData;
}
