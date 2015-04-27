//
//  functions.cpp
//  20150427Calendar
//
//  Created by 朝倉明俊 on 平成27年4月27日.
//  Copyright (c) 平成27年 朝倉明俊. All rights reserved.
//

#include <iostream>
#include "functions.h"

using namespace std;

int calendarFunctions::dayPerMonthC(int year, int month) {
    int dayPerMonth[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    if (year % 4 == 0) {
        dayPerMonth[1] = 29;
    }
    return dayPerMonth[month - 1];
}

int calendarFunctions::dayWeeksC (int year, int month) {
    if (month <= 2) {
        month += 12;
        year--;
    }
    int dayWeeks = (2 + 2 * month + 3 * (month + 1) / 5 + year + year / 4 - year / 100 + year / 400) % 7;
    return dayWeeks;
}

int calendarFunctions::getYear() {
    int year = 0;
    cout << "年を入力してください：" << endl;
    cin >> year;
    for (bool yearIsNumber; yearIsNumber == false;) {
        if (cin.fail()) {
            yearIsNumber = false;
            cout << "数字を入力してください！" << endl;
            scanf("%d", &year);
        } else {
            yearIsNumber = true;
        }
    }
    return year;
}

int calendarFunctions::getMonth() {
    int month = 0;
    cout << "月を入力してください：" << endl;
    cin >> month;
    for (bool monthIsCorrect = false; monthIsCorrect == false; ) {
        if (cin.fail()) {
            monthIsCorrect = false;
            cout << "数字を入力してください！" << endl;
            cin >> month;
        } else if (month < 1 || month > 12) {
            monthIsCorrect = false;
            cout << "入力した月は存在しません。\n入力直してください。" << endl;
            cin >> month;
        } else {
            monthIsCorrect = true;
        }
    }
    return month;
}

void calendarFunctions::outputCalendar (int year, int month, int dayPerMonth, int dayWeeks) {
    int yearJapanese = 0;
    int type;
    if (year >= 1926) {
        if (year == 1926) {
            if (month != 12) {
                type = 0;
            } else {
                type = 1;
            }
        } else if (year <= 1989) {
            if (year == 1989) {
                if (month == 1) {
                    type = 2;
                }
            } else {
                yearJapanese = year - 1926 + 1;
                type = 3;
            }
        } else if (year > 1989) {
            yearJapanese = year - 1989 + 1;
            type = 4;
        }
        switch (type) {
            case 0:
                cout << "大正26年" << endl;
                break;
            case 1:
                cout << "大正26年（12月25日まで）" << endl;
                cout << "昭和元年（12月25日から）" << endl;
                break;
            case 2:
                cout << "昭和64年（1月7日まで）" << endl;
                cout << "平成元年（1月8日から）" << endl;
                break;
            case 3:
                cout << "昭和" << yearJapanese << "年" << endl;
                break;
            case 4:
                cout << "平成" << yearJapanese << "年" << endl;
                break;
            default:
                break;
        }
    }
    cout << "西暦" << year << "年" << "　" << month << "月" << endl;
    cout << "--------------------------" << endl;
    cout << "日" << "  " << "月" << "　 " << "火" << "  " << "水" << "　 " << "木" << "  " << "金" << "　 " << "土" << endl;
    for (int i = 0; i != dayWeeks; i++) {
        cout << "    ";
    }
    for (int i = 0; i != dayPerMonth; i++) {
        cout << (i + 1);
        if (i < 9) {
            cout << "   ";
        } else {
            cout << "  ";
        }
        if ((i + dayWeeks + 1) % 7 == 0) {
            cout << endl;
        }
    }
}
