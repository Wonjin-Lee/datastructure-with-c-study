//
//  DBLinkedList.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 21..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "DBLinkedList.h"

void ListInit(List * plist)
{
    plist->head = NULL;
    plist->numOfData = 0;
}

void LInsert(List * plist, Data data)
{
    Node * newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    
    // 리스트에 노드가 없는 경우에
    // newNode의 next가 head를 가리키는 것은 NULL을 가리키는 것과 같다.
    newNode->next = plist->head;
    
    // head가 NULL을 가리키는게 아니라면(리스트에 노드가 있다면)
    // head가 가리키는 노드의 prev가 newNode를 가리키게 - 양방향이 되도록...
    if(plist->head != NULL)
        plist->head->prev = newNode;
    
    newNode->prev = NULL;
    plist->head = newNode;
    
    (plist->numOfData)++;
}

int LFirst(List * plist, Data * pdata)
{
    if(plist->head == NULL)
        return FALSE;
    
    plist->cur = plist->head;
    *pdata = plist->cur->data;
    
    return TRUE;
}

int LNext(List * plist, Data * pdata)
{
    if(plist->cur->next == NULL)
        return FALSE;
    
    plist->cur = plist->cur->next;
    *pdata = plist->cur->data;
    
    return TRUE;
}

// 양방향 연결 리스트이므로 왼쪽(head방향)으로도 조회가 가능해야 한다
int LPrevious(List * plist, Data * pdata)
{
    // 헤드가 가리키고 있는 노드(가장 왼쪽 노드)까지 왔을때
    if(plist->cur->prev == NULL)
        return FALSE;
    
    // 조회를 위한 cur이 바로 왼쪽의 노드를 가리키게 끔.
    plist->cur = plist->cur->prev;
    *pdata = plist->cur->data;
    
    return TRUE;
}

int LCount(List * plist)
{
    return plist->numOfData;
}
