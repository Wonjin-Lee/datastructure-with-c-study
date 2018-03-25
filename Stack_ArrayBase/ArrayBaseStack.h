//
//  ArrayBaseStack.h
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 23..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#ifndef ArrayBaseStack_h
#define ArrayBaseStack_h

#define TRUE        1
#define FALSE       0
#define STACK_LEN   100

typedef int Data;

typedef struct _arrayStack
{
    Data stackArr[STACK_LEN];
    int topIndex;
} ArrayStack;

typedef ArrayStack Stack;

void StackInit(Stack * pstack);
int SIsEmpty(Stack * pstack);

void SPush(Stack * pstack, Data data);
Data SPop(Stack * pstack);
Data SPeek(Stack * pstack);

#endif /* ArrayBaseStack_h */
