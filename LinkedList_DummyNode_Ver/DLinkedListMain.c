//
//  DLinkedListMain.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 13..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include "DLinkedList.h"

// 우선 순위 정하는 방법을 기술한 함수.
// 사용자가 원하는대로 기술할 수 있도록 메인에서 정의.
int WhoIsPrecede(int d1, int d2)
{
    if(d1 < d2)
        return 0;
    else
        return 1;
}

int main(void)
{
    // 리스트의 생성 및 초기화
    List list;
    int data;
    ListInit(&list);
    
    // 위에서 정의한 정렬 방법을 기술한 함수를 매개변수로 초기화.
    SetSortRule(&list, WhoIsPrecede);
    
    // 5개의 데이터 저장
    LInsert(&list, 11); LInsert(&list, 11);
    LInsert(&list, 22); LInsert(&list, 22);
    LInsert(&list, 33);
    
    // 저장된 데이터의 전체 출력
    printf("현재 데이터의 수 : %d \n", LCount(&list));
    
    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        while(LNext(&list, &data))
        {
            printf("%d ", data);
        }
    }
    printf("\n\n");
    
    // 숫자 22를 검색하여 모두 삭제
    if(LFirst(&list, &data))
    {
        if(data == 22)
            LRemove(&list);
        
        while(LNext(&list, &data))
        {
            if(data == 22)
                LRemove(&list);
        }
    }
    
    // 삭제 후 남아있는 데이터 전체 출력
    
    printf("현재 데이터의 수 : %d \n", LCount(&list));

    if(LFirst(&list, &data))
    {
        printf("%d ", data);
        
        while(LNext(&list, &data))
        {
            printf("%d ", data);
        }
    }
    printf("\n\n");
    return 0;
}
