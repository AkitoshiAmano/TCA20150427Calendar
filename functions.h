//
//  functions.h
//  20150427Calendar
//
//  Created by 朝倉明俊 on 平成27年4月27日.
//  Copyright (c) 平成27年 朝倉明俊. All rights reserved.
//

#ifndef ___0150427Calendar__functions__
#define ___0150427Calendar__functions__

#include <iostream>
#include <stdio.h>

class calendarFunctions {
public:
    int dayPerMonthC(int year, int month);
    int dayWeeksC(int year, int month);
    void outputCalendar(int year, int month, int dayPerMonth, int dayWeeks);
    int getYear();
    int getMonth();
};

#endif /* defined(___0150427Calendar__functions__) */
