//
//  DBLinkedListDummy.h
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 21..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#ifndef DBLinkedListDummy_h
#define DBLinkedListDummy_h

#include <stdio.h>


#define TRUE        1
#define FALSE       0

typedef int Data;

typedef struct _node
{
    Data data;
    struct _node * next;
    struct _node * prev;
} Node;

typedef struct _dbDLinkedList
{
    Node * head;
    Node * tail;
    Node * cur;
    int numOfData;
} DBLinkedList;

typedef DBLinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, Data data);

int LFirst(List * plist, Data * pdata);
int LNext(List * plist, Data * pdata);
//int LPrevious(List * plist, Data * pdata);

Data LRemove(List * plist);
int LCount(List * plist);

#endif /* DBLinkedListDummy_h */
