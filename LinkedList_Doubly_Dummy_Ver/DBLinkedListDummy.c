//
//  DBLinkedListDummy.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 21..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedListDummy.h"

void ListInit(List * plist)
{
    // 양방향 연결 리스트의 양 쪽 끝에(head, tail) 더미(dummy)를 생성
    plist->head = (Node*)malloc(sizeof(Node));
    plist->tail = (Node*)malloc(sizeof(Node));
    plist->numOfData = 0;
    
    plist->head->prev = NULL;
    plist->tail->next = NULL;
    
    // 리스트 초기화시에 head의 더미와 tail의 더미가 서로를 가리키도록
    plist->head->next = plist->tail;
    plist->tail->prev = plist->head;
}

void LInsert(List * plist, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    // 새로운 노드(newNode)의 prev가 기존의 tail의 prev가 가리키던 노드(가장 최근 삽입 노드)
    // 를 가리키도록
    newNode->prev = plist->tail->prev;
    
    // newNode 삽입 이전 가장 최근 삽입 노드의 next가 newNode를 가리키도록
    plist->tail->prev->next = newNode;
    
    // newNode의 next가 tail의 더미를 가리키도록
    // 지금 구현하는 양방향 연결 리스트는 노드 삽입시 tail에 삽입
    newNode->next = plist->tail;
    
    // tail의 더미의 prev가 newNode를 가리키도록
    plist->tail->prev = newNode;
    
    (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
    if(plist->head->next == plist->tail)
        return FALSE;
    plist->cur = plist->head->next;
    *pdata = plist->cur->data;
    
    return TRUE;
}

int LNext(List * plist, Data * pdata)
{
    if(plist->cur->next == plist->tail)
        return FALSE;
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    
    return TRUE;
}

Data LRemove(List * plist)
{
    Node * rpos = plist->cur;
    Data rdata = rpos->data;
    
    // 해당 노드를 삭제하기 전, 해당 노드의 전.후의 노드가 가리키는 방향을 수정해줌
    plist->cur->prev->next = plist->cur->next;
    plist->cur->next->prev = plist->cur->prev;
    
    // cur의 위치도 수정 !
    plist->cur = plist->cur->prev;
    
    free(rpos);
    (plist->numOfData)--;
    return rdata;
}

int LCount(List * plist)
{
    return plist->numOfData;
}
