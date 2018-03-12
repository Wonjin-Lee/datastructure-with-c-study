//
//  LinkedRead.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 11..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    int data;
    struct _node * next;
} Node;

int main(void)
{
    Node * head = NULL;
    Node * tail = NULL;
    Node * cur = NULL;
    
    Node * newNode = NULL;
    int readData;
    
    while(1)
    {
        printf("자연수 입력 : ");
        scanf("%d", &readData);
        
        if(readData < 1)
            break;
        
        newNode = (Node*)malloc(sizeof(Node));
        newNode->data = readData;
        newNode->next = NULL;
        
        if(head == NULL)
            head = newNode;
        else
            tail->next = newNode;
        tail = newNode;
    }
    
    // 조회
    if(head == NULL)
    {
        printf("저장된 자연수가 존재하지 않습니다. \n");
    }
    else
    {
        cur = head;
        printf("%d ", cur->data);
        
        while(cur->next != NULL)
        {
            cur = cur->next;
            printf("%d ", cur->data);
        }
    }
    printf("\n");
    
    // 삭제
    if(head == NULL)
    {
        return 0; // 연결리스트에 저장된 원소가 없으면 프로그램 종료
    }
    else
    {
        Node * delNode = head;
        Node * delNextNode = head->next;
        
        printf("%d를 삭제합니다. \n", head->data);
        free(delNode);
        
        while(delNextNode != NULL)
        {
            delNode = delNextNode;
            delNextNode = delNode->next;
            
            printf("%d를 삭제합니다. \n", delNode->data);
            free(delNode);
        }
    }
    
}
