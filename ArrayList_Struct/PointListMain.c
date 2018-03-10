//
//  PointListMain.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 10..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "Point.h"

int main(void)
{
    List list;
    Point compPos;
    Point * ppos;
    
    ListInit(&list);
    
    // 4개의 데이터 저장
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 1);
    LInsert(&list, ppos);
    
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 2, 2);
    LInsert(&list, ppos);
    
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 1);
    LInsert(&list, ppos);
    
    ppos = (Point*)malloc(sizeof(Point));
    SetPointPos(ppos, 3, 2);
    LInsert(&list, ppos);
    
    // 저장된 데이터의 출력
    printf("현재 데이터의 수 : %d \n", LCount(&list));
    
    if(LFirst(&list, &ppos))
    {
        ShowPointPos(ppos);
        
        while(LNext(&list, &ppos))
            ShowPointPos(ppos);
    }
    
    printf("\n");
    
    compPos.xpos = 2;
}
