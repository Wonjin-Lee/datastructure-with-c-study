//
//  LinkedRead_Repeat.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 12..
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
    
    if(head == NULL)
    {
        printf("연결리스트에 원소가 없습니다. \n");
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
    
    if(head == NULL)
    {
        printf("원소가 없습니다. \n");
        return 0;
    }
    else
    {
        Node * delNode = head;
        Node * delNextNode = head->next;
        
        printf("%d 삭제 \n", head->data);
        free(delNode);
        
        while(delNextNode != NULL)
        {
            delNode = delNextNode;
            delNextNode = delNode->next;
            
            printf("%d 삭제 \n", delNode->data);
            free(delNode);
        }
    }
}
