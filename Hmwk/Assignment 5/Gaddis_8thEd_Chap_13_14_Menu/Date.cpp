/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Date.h"
#include <iostream>
using namespace std;

void Date::SetYear(int year) {
    this->year = year;
}

int Date::GetYear() const {
    return year;
}

void Date::SetDay(int day) {
    this->day = day;
}

int Date::GetDay() const {
    return day;
}

void Date::SetMonth(int month) {
    this->month = month;
}

int Date::GetMonth() const {
    return month;
}

/*
 * Format 12/25/2017
 */
void Date::Print_mm_dd_yyyy() {
    cout << this->month << "/" << this->day << "/" << this->year << endl;
}

/*
 * Format December 25 2017
 */
void Date::Print_m_dd_yyyy() {
    cout << displayMonth(this->month) << " " << this->day << ", " << this->year << endl;
}

/*
 * Format 25 December 2017
 */
void Date::Print_dd_m_yy() {
    cout << GetDay() << " " << displayMonth(this->month) << " " << GetYear() << endl;
}

string Date::displayMonth(int m) {
    string name;
    switch (m) {
        case 1: name = "January";
            break;
        case 2: name = "February";
            break;
        case 3: name = "March";
            break;
        case 4: name = "April";
            break;
        case 5: name = "May";
            break;
        case 6: name = "June";
            break;
        case 7: name = "July";
            break;
        case 8: name = "August";
            break;
        case 9: name = "September";
            break;
        case 10: name = "October";
            break;
        case 11: name = "November";
            break;
        case 12: name = "December";
    }
    return name;
}