//
//  SelectionSort.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 4. 9..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>

void SelectionSort(int arr[], int n)
{
    int temp, maxIdx;
    
    for(int i=0; i<n-1; i++)
    {
        maxIdx = i;
        
        // 최소값을 탐색하는 반복문
        for(int j=i+1; j<n; j++)
        {
            // 기준점(maxIdx)보다 뒤에 있는 데이터(arr[j])가 작으면
            // 기준점을 j로 최신화한다
            if(arr[j] < arr[maxIdx])
                maxIdx = j;
        }
        
        // 데이터 교환
        temp = arr[i];
        arr[i] = arr[maxIdx];
        arr[maxIdx] = temp;
    }
}

int main(void)
{
    int arr[4] = {3, 4, 2, 1};
    
    SelectionSort(arr, sizeof(arr)/sizeof(int));
    
    for(int i=0; i<4; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    
    return 0;
}
