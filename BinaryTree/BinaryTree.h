//
//  BinaryTree.h
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 31..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#ifndef BinaryTree_h
#define BinaryTree_h

typedef int BTData;

typedef struct _bTreeNode
{
    BTData data;
    struct _bTreeNode * left;
    struct _bTreeNode * right;
} BTreeNode;

BTreeNode * MakeBTreeNode(void);
BTData GetData(BTreeNode * bt);
void SetData(BTreeNode * bt, BTData data);

BTreeNode * GetLeftSubTree(BTreeNode * bt);
BTreeNode * GetRightSubTree(BTreeNode * bt);

void MakeLeftSubTree(BTreeNode * main, BTreeNode * sub);
void MakeRightSubTree(BTreeNode * main, BTreeNode * sub);

void DeleteTree(BTreeNode * bt);

void PreorderTraverse(BTreeNode * bt);
void InorderTraverse(BTreeNode * bt);
void PostorderTraverse(BTreeNode * bt);


#endif /* BinaryTree_h */

