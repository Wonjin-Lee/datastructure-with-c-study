//
//  DLinkedList.h
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 13..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#ifndef DLinkedList_h
#define DLinkedList_h

#define TRUE        1
#define FALSE       0

// 자료형을 LData로 재정의하여 자료형을 유동적으로 바꿀 수 있도록 함.
typedef int LData;

// 연결 리스트의 저장 공간.
typedef struct _node
{
    LData data;
    struct _node * next;
} Node;

// 리스트 구조체 변수를 생성하면 기본적으로 가지고 있는 각종 변수들.
typedef struct _linkedList
{
    Node * head;
    Node * cur;
    Node * before;
    int numOfData;
    // 데이터 삽입시에 정렬 기준을 적용하기 위한 멤버.
    int (*comp)(LData d1, LData d2);
} LinkedList;

typedef LinkedList List;

void ListInit(List * plist);
void LInsert(List * plist, LData data);

int LFirst(List * plist, LData * pdata);
int LNext(List * plist, LData * pdata);

LData LRemove(List * plist);
int LCount(List * plist);

// List 구조체 멤버를 통해 리스트를 정렬하는 함수.
void SetSortRule(List * plist, int (*comp)(LData d1, LData d2));

#endif /* DLinkedList_h */
