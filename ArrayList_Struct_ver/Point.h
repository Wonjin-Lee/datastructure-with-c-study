//
//  Point.h
//  DataStructure
//
//  Created by LEE WON JIN on 2018. 3. 10..
//  Copyright © 2018년 LEE WON JIN. All rights reserved.
//

#ifndef Point_h
#define Point_h

#include <stdio.h>

typedef struct _point
{
    int xpos;
    int ypos;
} Point;

// Point 변수의 xpos, ypos 값 설정
voi d SetPointPos(Point * ppos, int xpos, int ypos);

// Point 변수의 xpos, ypos 정보 출력
void ShowPointPos(Point * ppos);

// 두 Point 변수의 비교
int PointComp(Point * pos1, Point * pos2);

#endif /* Point_h */
