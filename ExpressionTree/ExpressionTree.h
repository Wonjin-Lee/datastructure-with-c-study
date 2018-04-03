//
//  ExpressionTree.h
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 4. 3..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#ifndef ExpressionTree_h
#define ExpressionTree_h

#include "BinaryTree.h"

BTreeNode * MakeExpTree(char exp[]);
int EvaluateExpTree(BTreeNode * bt);

void ShowPrefixTypeExp(BTreeNode * bt);
void ShowInfixTypeExp(BTreeNode * bt);
void ShowPostfixTypeExp(BTreeNode * bt);

#endif /* ExpressionTree_h */
