/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on May 2, 2017, 2:23 PM
 */

#include <cstdlib>
#include <iostream>
#include "Date.h"
using namespace std;

bool cinValidNumber(int &);

/*
 * 
 */
int main(int argc, char** argv) {
    Date date;
    int day, month, year;
    //input day
    do {
        do {
            cout << "Enter day: ";
        } while (!cinValidNumber(day));
    } while (day > 31 || day < 1);
    date.SetDay(day);
    //input month
    do {
        do {
            cout << "Enter month: ";
        } while (!cinValidNumber(month));
    } while (month > 12 || month < 1);
    date.SetMonth(month);
    //input year
    do {
        cout << "Enter year: ";
    } while (!cinValidNumber(year));
    date.SetYear(year);
    //print output
    date.Print_dd_m_yy();
    date.Print_m_dd_yyyy();
    date.Print_mm_dd_yyyy();
    return 0;
}

bool cinValidNumber(int &number) {
    float temp;
    cin >> temp;
    number = static_cast<int> (temp);
    bool isCorrect = true;
    if (cin.fail()) {

        cin.clear();
        cin.ignore(80, '\n');
        isCorrect = false;
    }
    return isCorrect;
}