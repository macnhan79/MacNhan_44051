/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "DayOfYear2.h"

DayOfYear2::DayOfYear2(unsigned int days, string month) {
    this->days = days;
    this->month = month;
    if (days > dayOfMonths[displayMonth() - 1]) {
        cout << "The day is outside the range of days for the month" << endl;
        this->~DayOfYear2();
        exit(0);
    }
}

//DayOfYear2::~DayOfYear2() {
//    
//}

void DayOfYear2::SetMonth(string month) {
    this->month = month;
}

string DayOfYear2::GetMonth() const {
    return month;
}

void DayOfYear2::SetDays(unsigned int days) {
    this->days = days;
}

unsigned int DayOfYear2::GetDays() const {
    return days;
}

void DayOfYear2::print() {
    int totalDays = 0;
    int i_month = displayMonth() - 1;
    for (int i = 0; i < i_month; i++) {
        totalDays += dayOfMonths[i];
    }
    totalDays += days;
    cout << month << " " << days << " would be day " << totalDays;
}

int DayOfYear2::displayMonth() {
    if (month == "January") {
        return 1;
    } else if (month == "February") {
        return 2;
    } else if (month == "March") {
        return 3;
    } else if (month == "April") {
        return 4;
    } else if (month == "May") {
        return 5;
    } else if (month == "June") {
        return 6;
    } else if (month == "July") {
        return 7;
    } else if (month == "August") {
        return 8;
    } else if (month == "September") {
        return 9;
    } else if (month == "October") {
        return 10;
    } else if (month == "November") {
        return 11;
    } else if (month == "December") {
        return 12;
    } else {
        return 1;
    }

}