//
//  main.cpp
//  20150427Calendar
//
//  Created by 朝倉明俊 on 平成27年4月27日.
//  Copyright (c) 平成27年 朝倉明俊. All rights reserved.
//

#include <iostream>
#include "functions.h"

using namespace std;

int main(int argc, const char * argv[]) {
    int year, month;
    int dayPerMonth;
    int dayWeeks;
    year = (calendarFunctions()).getYear();
    month = (calendarFunctions()).getMonth();
    dayPerMonth = (calendarFunctions()).dayPerMonthC(year, month);
    dayWeeks = (calendarFunctions()).dayWeeksC(year, month);
    (calendarFunctions()).outputCalendar(year, month, dayPerMonth, dayWeeks);
}