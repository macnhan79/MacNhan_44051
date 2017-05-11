/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "NumDays.h"

NumDays::NumDays() {
    this->hours = 0;
    this->days = 0;
}

NumDays::NumDays(int hours) {
    this->hours = hours;
    this->days = hours / 8.0f;
}

float NumDays::GetDays() const {
    return days;
}

void NumDays::SetHours(int hours) {
    this->hours = hours;
    this->days = hours / 8.0f;
}

int NumDays::GetHours() const {
    return hours;
}
//***********************************************
//Overloaded binary + operator
//***********************************************

NumDays NumDays::operator+(const NumDays &right) {
    NumDays temp(hours + right.hours);
    return temp;
}
//***********************************************
//Overloaded binary - operator
//***********************************************

NumDays NumDays::operator-(const NumDays &right) {
    NumDays temp(hours - right.hours);
    return temp;
}

NumDays NumDays::operator++() {
    ++hours;
    days = hours / 8.0f;
    return *this;
}

NumDays NumDays::operator++(int) {
    NumDays temp(hours);
    hours++;
    days = hours / 8.0f;
    return temp;
}

NumDays NumDays::operator--() {
    --hours;
    days = hours / 8.0f;
    return *this;
}

NumDays NumDays::operator--(int) {
    NumDays temp(hours);
    hours--;
    days = hours / 8.0f;
    return temp;
}



