//
//  DBLinkedList.h
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 21..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#ifndef DBLinkedList_h
#define DBLinkedList_h

#define TRUE        1
#define FALSE       0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node * next;
    // 양방향으로 리스트를 이어주기 위해 prev 구조체 포인터 변수를 생성
    struct _node * prev;
} Node;

typedef struct _DLinkedList
{
    Node * head;
    Node * cur;
    int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
int LPrevious(List * plist, Data * pdata);
int LCount(List * plist);

#endif /* DBLinkedList_h */
