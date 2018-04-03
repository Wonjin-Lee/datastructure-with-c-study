//
//  BinaryTree.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 31..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

// 트리를 구성하는 노드를 생성 후 그 노드의 주소를 가지고 있는
// 포인터 변수를 반환
BTreeNode * MakeBTreeNode(void)
{
    BTreeNode * nd = (BTreeNode*)malloc(sizeof(BTreeNode));
    
    nd->left = NULL;
    nd->right = NULL;
    return nd;
}

// 노드의 포인터 변수를 매개변수로 받아 그 노드의 값을 반환
BTData GetData(BTreeNode * bt)
{
    return bt->data;
}

// 노드에 값을 지정해준다
void SetData(BTreeNode * bt, BTData data)
{
    bt->data = data;
}

// 매개변수로 넣은 노드의 왼쪽에 있는 노드를 반환
BTreeNode * GetLeftSubTree(BTreeNode * bt)
{
    return bt->left;
}

// 매개변수로 넣은 노드의 오른쪽에 있는 노드를 반환
BTreeNode * GetRightSubTree(BTreeNode * bt)
{
    return bt->right;
}

// main노드의 왼쪽 노드 자리에 sub노드를 연결한다
// 그 자리에 이미 노드가 있으면 그 노드와 그에 연결된 모든 노드를 삭제 후
// sub노드를 연결한다
void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub)
{
    if(main->left != NULL)
        DeleteTree(main->left);
    
    main->left = sub;
}

// main노드의 오른쪽 노드 자리에 sub노드를 연결한다
// 그 자리에 이미 노드가 있으면 그 노드와 그에 연결된 모든 노드를 삭제 후
// sub노드를 연결한다
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub)
{
    if(main->right != NULL)
        DeleteTree(main->right);
    
    main->right = sub;
}

// 노드를 삭제하는 함수
// 재귀적으로 작동하면서 해당 노드의 아래에 있는 노드도
// 모두 삭제
void DeleteTree(BTreeNode * bt)
{
    if(bt == NULL)
        return;
    
    DeleteTree(bt->left);
    DeleteTree(bt->right);
    printf("%d 삭제 \n", bt->data);
    free(bt);
}

// 전위 순회 방식으로 노드를 돌면서 트리를 출력
void PreorderTraverse(BTreeNode * bt)
{
    if(bt == NULL)
        return;
    
    printf("%d \n", bt->data);
    PreorderTraverse(bt->left);
    PreorderTraverse(bt->right);
}

// 중위 순회 방식으로 노드를 돌면서 트리를 출력
void InorderTraverse(BTreeNode * bt)
{
    if(bt == NULL)
        return;
    
    InorderTraverse(bt->left);
    printf("%d \n", bt->data);
    InorderTraverse(bt->right);
}

// 후위 순회 방식으로 노드를 돌면서 트리를 출력
void PostorderTraverse(BTreeNode * bt)
{
    if(bt == NULL)
        return;
    
    PostorderTraverse(bt->left);
    PostorderTraverse(bt->right);
    printf("%d \n", bt->data);
}

