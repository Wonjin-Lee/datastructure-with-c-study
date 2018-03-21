//
//  CLinkedListMain.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 14..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "CLinkedList.h"

int main(void)
{
    // 원형 연결 리스트의 생성 및 초기화
    List list;
    int number, nodeNum;
    char * name = (char*)malloc(sizeof(char));
    ListInit(&list);
    
    LInsert(&list, 1, "LeeWonJin"); LInsert(&list, 2, "LeeHaYoung");
    LInsert(&list, 3, "LeeInAe"); LInsert(&list, 4, "LeeYongHo");
    LInsert(&list, 5, "JoBokShim");
    
    
    nodeNum = LCount(&list);
    
    if(nodeNum != 0)
    {
        LFirst(&list, &number, &name);
        printf("[%d, %s] ", number, name);
        
        for(int i=0; i<nodeNum-1; i++)
        {
            LNext(&list, &number, &name);
            printf("[%d, %s] ", number, name);
        }
    }
    
    printf("\n");
    return 0;
}
