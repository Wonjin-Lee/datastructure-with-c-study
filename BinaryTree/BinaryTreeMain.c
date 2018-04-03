//
//  BinaryTreeMain.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 31..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include "BinaryTree.h"

int main(void)
{
    // 노드 7개 생성
    BTreeNode * bt1 = MakeBTreeNode();
    BTreeNode * bt2 = MakeBTreeNode();
    BTreeNode * bt3 = MakeBTreeNode();
    BTreeNode * bt4 = MakeBTreeNode();
    BTreeNode * bt5 = MakeBTreeNode();
    BTreeNode * bt6 = MakeBTreeNode();
    BTreeNode * bt7 = MakeBTreeNode();
    
    
    // 노드에 데이터 삽입
    SetData(bt1, 1); SetData(bt2, 2);
    SetData(bt3, 3); SetData(bt4, 4);
    SetData(bt5, 5); SetData(bt6, 6);
    SetData(bt7, 7);
    
    
    // 1번 노드 부터 차례대로 가지를 쳐서 포화 트리를 만듬
    MakeLeftSubTree(bt1, bt2);
    MakeRightSubTree(bt1, bt3);
    MakeLeftSubTree(bt2, bt4);
    MakeRightSubTree(bt2, bt5);
    MakeLeftSubTree(bt3, bt6);
    MakeRightSubTree(bt3, bt7);
    
    //
    printf("<<< 전위 순회 >>> \n");
    PreorderTraverse(bt1);
    printf("\n");
    printf("<<< 중위 순회 >>> \n");
    InorderTraverse(bt1);
    printf("\n");
    printf("<<< 후위 순회 >>> \n");
    PostorderTraverse(bt1);
    printf("\n");
    
    // 새로운 노드를 생성 후 값 지정
    BTreeNode * bt8 = MakeBTreeNode();
    SetData(bt8, 8);
    
    // 루트 노드의 왼쪽 노드 자리에 새로운 노드(bt8 삽입)
    // 그 자리에 이미 bt2 노드가 있다
    // bt2와 그 밑의 모든 노드를 삭제 후 bt8 노드를 연결
    MakeLeftSubTree(bt1, bt8);
    printf("\n");
    
    // bt8 노드 연결 후 전위 순휘
    printf("<<< 전위 순회 >>> \n");
    PreorderTraverse(bt1);
    printf("\n");
    
    return 0;
}

