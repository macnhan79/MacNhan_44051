/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */


#include "DayOfYear.h"

DayOfYear::DayOfYear(unsigned int days) {
    this->days = days;
}

void DayOfYear::SetDays(unsigned int days) {
    this->days = days;
}

unsigned int DayOfYear::GetDays() const {
    return days;
}

void DayOfYear::print() {
    if (days > 365) days = 365;
    int dayOfMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    unsigned int day = days;
    for (int i = 0; i < 12; i++) {
        this->month = displayMonth(i + 1);
        if (day <= dayOfMonths[i]) {
            cout << "Day " << days << " would be "
                    << this->month << " " << day << endl;
            break;
        }
        day = day - dayOfMonths[i];
    }

}

string DayOfYear::displayMonth(int m) {
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