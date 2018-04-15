//
//  InsertionSort.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 4. 15..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>

void inserSort(int arr[], int n)
{
    int i, j;
    
    int insData;
    
    // 배열의 두 번째 인덱스부터 마지막 인덱스까지 전부 확인
    for(i=1; i<n; i++)
    {
        insData = arr[i];
        
        // 위의 i인덱스부터 0 인덱스까지 arr[i]와 값을 비교하면서 자리를 찾도록 함
        for(j=i-1; j>=0; j--)
        {
            if(arr[j] > insData)
                arr[j+1] = arr[j];
            else
                break;
        }
        
        // 위의 for문이 완료되면 [j+1]위치가 arr[i]가 삽입되야 할 위치
        // [j+1]인 이유는 위의 for문에서 마지막으로 j--이 되고 반복이 끝나기때문
        arr[j+1] = insData;
    }
}

int main(void)
{
    int arr[5] = {5, 3, 2, 4, 1};

    inserSort(arr, sizeof(arr)/sizeof(int));
    
    for(int i=0; i<5; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    return 0;
}
