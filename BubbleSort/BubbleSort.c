//
//  BubbleSort.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 4. 9..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>

void BubbleSort(int arr[], int n)
{
    int temp;
    
    // 가장 오른쪽으로 보낸 원소는 비교 대상에서 제외
    for(int i=0; i<n-1; i++)
    {
        // 배열을 비교하면서 정렬하는 반복문
        for(int j=0; j<(n-i)-1; j++)
        {
            // 앞의 원소가 뒤에 있는 원소보다 클 경우 뒤로 보냄
            if(arr[j] > arr[j+1])
            {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(void)
{
    int arr[4] = {3, 2, 4, 1};
    
    BubbleSort(arr, sizeof(arr)/sizeof(int));
    
    for(int i=0; i<4; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    return 0;
}
