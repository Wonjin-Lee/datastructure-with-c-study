//
//  CLinkedList.h
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 14..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#ifndef CLinkedList_h
#define CLinkedList_h

#define TRUE        1
#define FALSE       0

typedef int Number;
typedef char * Name;

typedef struct _node
{
    Number number;
    Name name;
    struct _node * next;
} Node;

typedef struct _CLL
{
    Node * tail;
    Node * cur;
    Node * before;
    int numOfData;
} CList;

typedef CList List;

void ListInit(List * plist);
void LInsert(List * plist, Number number, Name name);
void LInsertFront(List * plist, Number number, Name name);

int LFirst(List * plist, Number * pnumber, Name * pname);
int LNext(List * plist, Number * pnumber, Name * pname);
Name LRemove(List * plist);
int LCount(List * plist);

#endif /* CLinkedList_h */
