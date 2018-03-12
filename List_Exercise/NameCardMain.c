//
//  NameCardMain.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 11..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "NameCard.h"
#include "ArrayList.h"

int main(void)
{
    List list;
    
    NameCard * newCard;
    
    ListInit(&list);
    
    newCard = MakeNameCard("wonjin", "01046270690");
    LInsert(&list, newCard);
    
    newCard = MakeNameCard("hayoung", "01047960514");
    LInsert(&list, newCard);
    
    newCard = MakeNameCard("Inae", "01093450675");
    LInsert(&list, newCard);
    
    if(LFirst(&list, &newCard))
    {
        if(!NameCompare(newCard, "hayong"))
        {
            ShowNameCardInfo(newCard);
        }
        else
            while(LNext(&list, &newCard))
            {
                if(!NameCompare(newCard, "hayoung"))
                {
                    ShowNameCardInfo(newCard);
                    break;
                }
            }
    }
    
    if(LFirst(&list, &newCard))
    {
        if(!NameCompare(newCard, "Inae"))
        {
            ChangePhoneNum(newCard, "01012345678");
        }
        else
            while(LNext(&list, &newCard))
            {
                if(!NameCompare(newCard, "Inae"))
                {
                    ChangePhoneNum(newCard, "01012345678");
                    break;
                }
            }
    }
    
    if(LFirst(&list, &newCard))
    {
        if(!NameCompare(newCard, "wonjin"))
        {
            newCard = LRemove(&list);
            free(newCard);
        }
        else
            while(LNext(&list, &newCard))
            {
                if(!NameCompare(newCard, "wonjin"))
                {
                    newCard = LRemove(&list);
                    free(newCard);
                    break;
                }
            }
    }
}
