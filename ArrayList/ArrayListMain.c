//
//  ArrayListMain.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 9..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include "ArrayList.h"

int main(){
    ArrayList list;
    
    ListInit(&list);
    
    for(int i=1; i<10; i++){ // 리스트에 저장 1부터 9까지
        LInsert(&list, i);
    }
    printf("%d \n", LCount(&list));
    
    int data;
    
    int sum = 0;
    
    if(LFirst(&list, &data)){
        sum += data;
        while(LNext(&list, &data)){
            sum += data;
        }
    }
    printf("%d \n", sum);
    
    if(LFirst(&list, &data)){
        if(data % 2 == 0 || data % 3 ==0){
            LRemove(&list);
        }
        while(LNext(&list, &data)){
            if(data % 2 == 0 || data % 3 ==0){
                LRemove(&list);
            }
        }
    }
    
    if(LFirst(&list, &data)){
        printf("%d ", data);
        while(LNext(&list, &data)){
            printf("%d ", data);
        }
    }
    printf("\n");
}
