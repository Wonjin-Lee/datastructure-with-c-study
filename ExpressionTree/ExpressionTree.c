
//
//  ExpressionTree.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 4. 3..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "ListBaseStack.h"
#include "BinaryTree.h"

//
BTreeNode * MakeExpTree(char exp[])
{
    // 피연산자와 연산자를 잠시 보관하고 꺼내어 트리를 만들기 위해
    // 스택을 생성
    Stack stack;
    
    BTreeNode * pnode;
    
    int expLen = strlen(exp);
    
    StackInit(&stack);
    
    // 수식의 길이만큼 반복
    for(int i=0; i<expLen; i++)
    {
        // 새로운 트리 노드를 생성
        pnode = MakeBTreeNode();
        
        // exp[i]가 피연산자면 새로 생성한 트리 노드에 값을 지정해 준다
        if(isdigit(exp[i]))
        {
            SetData(pnode, exp[i] - '0');
        }
        // 연산자이면 스택에서 피연산자 두 개를 빼서 노드의 양 옆에 붙임
        // 먼저 들어간 피연산자가 왼쪽 서브트리로 와야하기 때문에 오른쪽 서브트리에
        // 먼저 pop연산으로 나온 노드를 연결해 준다
        else
        {
            MakeRightSubTree(pnode, SPop(&stack));
            MakeLeftSubTree(pnode, SPop(&stack));
            SetData(pnode, exp[i]);
        }
        // 피연산자든 연산의 결과로 만들어진 서브트리든 다시 스택에 넣는다
        SPush(&stack, pnode);
    }
    // 반복문이 끝나고 나온 최종 트리를 스택에서 pop해준다
    return SPop(&stack);
}

//
int EvaluateExpTree(BTreeNode * bt)
{
    int op1, op2;
    
    // 재귀를 탈출하기 위한 조건문
    // bt의 왼쪽 서브트리와 오른쪽 서브트리가 모두 NULL을 가리키고 있다면 bt는 리프노드다
    // 그러므로 bt의 data를 반환
    if(GetLeftSubTree(bt) == NULL && GetRightSubTree(bt) == NULL)
        return GetData(bt);
    
    // 트리의 특성상 재귀를 이용해서 최하단에서 부터 값을 가져온다
    op1 = EvaluateExpTree(bt->left);
    op2 = EvaluateExpTree(bt->right);
    
    switch (GetData(bt))
    {
        case '+':
            return op1 + op2;
            break;
            
        case '-':
            return op1 - op2;
            break;
        
        case '*':
            return op1 * op2;
            break;
        
        case '/':
            return op1 / op2;
            break;
    }
    return 0;
}

// 포인터 함수로 이용하기 위한 함수 정의
// 순회하면서 데이터를 출력하기 위한 함수이다
void ShowNodeData(int data)
{
    if(0<=data && data<=9)
        printf("%d ", data);
    else
        printf("%c ", data);
}

// 전위 순회
void ShowPrefixTypeExp(BTreeNode * bt)
{
    PreorderTraverse(bt, ShowNodeData);
}

// 중위 순회
void ShowInfixTypeExp(BTreeNode * bt)
{
    InorderTraverse(bt, ShowNodeData);
}

// 후위 순회
void ShowPostfixTypeExp(BTreeNode * bt)
{
    PostorderTraverse(bt, ShowNodeData);
}
