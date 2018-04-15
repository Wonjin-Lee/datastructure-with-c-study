//
//  MergeSort.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 4. 15..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>

// 두 개의 배열 구간을 병합하는 함수
void MergeTwoArea(int arr[], int left, int mid, int right)
{
    // 값 비교를 하기 위해
    // 두 구간의 첫 인덱스를 fIdx와 rIdx로 이용
    int fIdx = left;
    int rIdx = mid + 1;
    int i;
    
    // 임시의 배열 공간을 생성
    int * sortArr = (int*)malloc(sizeof(int)*(right+1));
    int sIdx = left;
    
    // 두 구간 전부 구간의 마지막 인덱스에 도달하지 않았으면
    // 계속해서 두 구간의 원소 값을 비교하면서 임시 배열 공간에
    // 값이 작은 순으로 저장
    while(fIdx <= mid && rIdx <= right)
    {
        if(arr[fIdx] <= arr[rIdx])
            sortArr[sIdx] = arr[fIdx++];
        else
            sortArr[sIdx] = arr[rIdx++];
        
        sIdx++;
    }
    
    // 두 구간의 어느 하나가 해당 구간의 마지막 인덱스를 넘어섰을 때
    // 그 구간이 왼쪽 구간이냐 오른쪽 구간이냐에 따라 아래 조건식에 들어감
    // 이 때는 어느 한 쪽 구간은 정렬이 완료 된 것 이므로
    // 남은 구간만 순서대로 임시 배열에 삽입하면 됨
    if(fIdx > mid)
    {
        for(i=rIdx; i <= right; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }
    else
    {
        for(i=fIdx; i <= mid; i++, sIdx++)
            sortArr[sIdx] = arr[i];
    }
    
    // 이제 임시 배열에 저장된 정렬된 배열 일부분을 순서대로 원래 배열에다가 저장
    for(i=left; i <= right; i++)
        arr[i] = sortArr[i];
    
    // 임시 배열은 필요가 없어졌으니 메모리 회수
    free(sortArr);
}

void MergeSort(int arr[], int left, int right)
{
    int mid;
    
    // left가 right보다 작은게 아니라면
    // 배열을 더 이상 나눌 수 없는 상태가 된 것
    if(left < right)
    {
        // left와 right 사이의 중간 인덱스 구하기
        mid = (left + right) / 2;
        
        // 배열을 중간을 기준으로 해서 왼쪽 편을 재귀적으로
        // 정렬한다
        MergeSort(arr, left, mid);
        
        // 배열을 중간을 기준으로 해서 오른쪽 편을 재귀적으로
        // 정렬한다
        MergeSort(arr, mid + 1, right);
        
        // 정렬된 두 배열을 병합한다
        MergeTwoArea(arr, left, mid, right);
    }
}

int main(void)
{
    int arr[7] = {3, 2, 4, 1, 7, 6, 5};
    
    MergeSort(arr, 0, sizeof(arr)/sizeof(int) - 1);
    
    for(int i=0; i<7; i++)
        printf("%d ", arr[i]);
    
    printf("\n");
    
    return 0;
}
