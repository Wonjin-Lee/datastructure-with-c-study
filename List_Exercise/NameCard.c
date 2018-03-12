//
//  NameCard.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 11..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#inlcude "NameCard.h"

NameCard * MakeNameCard(char * name, char * phone)
{
    NameCard * newCard = (NameCard*)malloc(sizeof(NameCard));
    strcpy(newCard->name, name);
    strcpy(newCard->phone, phone);
    
    return newCard;
}

void ShowNameCardInfo(NameCard * pcard)
{
    printf("Name : %s \n", pcard->name);
    printf("Phone : %s \n", pcard->phone);
}

int NameCompare(NameCard * pcard, char * name)
{
    return strcmp(pcard->name, name);
}

void ChangePhoneNum(NameCard * pcard, char * phone)
{
    strcpy(pcard->phone, phone);
}
