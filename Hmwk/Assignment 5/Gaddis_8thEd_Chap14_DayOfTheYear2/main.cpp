/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on May 9, 2017, 1:29 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "DayOfYear2.h"
using namespace std;
bool cinValidNumber(unsigned int &);

/*
 * 
 */
int main(int argc, char** argv) {
   
    unsigned int day;
    string month;
    do {
        cout << "Enter days: ";
    } while (!cinValidNumber(day));
    //input month
    cin.ignore();
    cout << "Enter month: ";
    getline(cin, month);
    DayOfYear2 day2(day, month);
    day2.print();
    return 0;
}

bool cinValidNumber(unsigned int &number) {
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
