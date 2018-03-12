//
//  free.c
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 11..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

void calcul(int * ptr);

#include <stdio.h>

int main(){
    int a = 30;
    int * ptr = &a;
    
    calcul(ptr);
    printf("%d", *ptr);
}
void calcul(int * ptr)
{
    *ptr = *ptr + 1;
}
