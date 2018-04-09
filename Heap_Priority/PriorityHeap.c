//
//  PriorityHeap.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 4. 8..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include "PriorityHeap.h"

// 힙을 초기화
void HeapInit(Heap * ph)
{
    ph->numOfData = 0;
}

// 힙이 비어있는지 확인하는 함수
int HIsEmpty(Heap * ph)
{
    if(ph->numOfData == 0)
        return TRUE;
    else
        return FALSE;
}

// 부모의 인덱스 값을 반환
// 매개변수가 왼쪽 자식이든 오른쪽 자식이든
// 정수형으로 반환되기 때문에 상관없다
int GetParentIDX(int idx)
{
    return idx / 2;
}

// 왼쪽 자식의 인덱스를 반환하는 함수
// 왼쪽 자식의 인덱스는 부모 인덱스 * 2 이다
int GetLChildIDX(int idx)
{
    return idx * 2;
}

// 오른쪽 자식의 인덱스를 반환하는 함수
// 오른쪽 자식의 인덱스는 (부모 인덱스 * 2) + 1 이다
int GetRChildIDX(int idx)
{
    return GetLChildIDX(idx) + 1;
}

// 매개 변수로 받은 인덱스의 자식 중 우선순위가 높은 자식의 인덱스를 반환해 주는 함수
// 3가지 경우로 함수가 진행 되는데, 왼쪽 자식이 없는 경우는 0을 반환 == 왼쪽 자식이 없으면 오른쪽 자식도 없다
// 왼쪽 자식의 인덱스와 힙의 전체 원소 개수와 동일할 때 == 왼쪽 자식 밖에 없다는 뜻이므로 왼쪽 자식 인덱스 반환
// 그 외에는 왼쪽 자식의 우선 순위와 오른쪽 자식의 우선 순위를 비교해서 우선 순위가 큰 자식 인덱스 반환
int GetHiPriChildIDX(Heap * ph, int idx)
{
    if(GetLChildIDX(idx) > ph->numOfData)
        return 0;
    else if(GetLChildIDX(idx) == ph->numOfData)
        return GetLChildIDX(idx);
    else
    {
        if(ph->heapArr[GetLChildIDX(idx)].pr > ph->heapArr[GetRChildIDX(idx)].pr)
            return GetRChildIDX(idx);
        else
            return GetLChildIDX(idx);
    }
}

// 힙에 원소를 삽입하는 함수
// 힙에 원소를 삽입할 때는 힙의 가장 밑에 삽입 후 부모와 비교하면서 부모보다 우선순위가 크면
// 위로 올려보낸다
void HInsert(Heap * ph, HData data, Priority pr)
{
    int idx = ph->numOfData + 1;
    HeapElem nelem = {pr,data};
    
    while(idx != 1)
    {
        // 새로운 원소의 우선순위가 현재 위치의 부모의 우선순위보다 높은 우선순위면(pr값이 작으면)
        if(pr < ph->heapArr[GetParentIDX(idx)].pr)
        {
            // 부모 원소를 현재 인덱스로 보내고 idx 를 부모 인덱스 값으로 최신화
            ph->heapArr[idx] = ph->heapArr[GetParentIDX(idx)];
            idx = GetParentIDX(idx);
        }
        else
            break;
    }
    
    ph->heapArr[idx] = nelem;
    ph->numOfData += 1;
}

// 힙에서 원소를 삭제하고 그 데이터 값을 반환하는 함수
// 힙에서 원소를 삭제할 때는 맨 위의 값을 삭제하고, 그 자리에 맨 밑에 있는 원소를 그 자리에 올린 후
// 자식의 우선순위와 비교해서 제 자리를 찾을 때 까지 밑으로 이동시킨다
HData HDelete(Heap * ph)
{
    // 반환하기 위해 삭제할 원소의 값을 저장
    HData retData = (ph->heapArr[1].data);
    HeapElem lastElem = ph->heapArr[ph->numOfData];
    
    int parentIdx = 1;
    int childIdx;
    
    // 현재 위치를 기준으로 우선순위가 높은 자식과 우선순위를 비교해서
    // 맨 위로 보낸 마지막 원소의 우선 순위가 더 높으면 반복문을 빠져나가고
    // parentIdx 자리에 마지막 원소를 최종적으로 삽입
    while(childIdx = GetHiPriChildIDX(ph, parentIdx))
    {
        if(lastElem.pr <= ph->heapArr[childIdx].pr)
            break;
        // 마지막원소의 우선순위가 더 작을 경우 비교했던 자식의 위치를 위로 올려준다
        // 그리고 parentIdx를 childIdx로 최신화
        ph->heapArr[parentIdx] = ph->heapArr[childIdx];
        parentIdx = childIdx;
    }
    
    ph->heapArr[parentIdx] = lastElem;
    ph->numOfData -= 1;
    return retData;
}
