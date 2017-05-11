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
using namespace std;
#include "NumDays.h"

/*
 * 
 */
int main(int argc, char** argv) {
    NumDays day(12);
    NumDays day2(24);
    NumDays day3(24);
    
    cout << "Days 1: " << day.GetDays() << endl;
    cout << "Days 2: " << day2.GetDays() << endl;
    cout << "Days 3: " << day3.GetDays() << endl;
    
    //add operator
    cout << "Days 1 + 2: " << day.operator+(day2).GetDays() << endl;
    //sub operator
    cout << "Days 3 - 1: " << day3.operator-(day).GetDays() << endl;
    //prefix increase
    NumDays temp = day++;
    cout << "Postfix increase Days 1: " << temp.GetDays() << endl;
    //postfix increase
    NumDays temp1 = ++day;
    cout << "Prefix increase Days 1: " << temp1.GetDays() << endl;
    //prefix decrease
    NumDays temp2 = day--;
    cout << "Postfix decrease Days 1: " << temp2.GetDays() << endl;
    //postfix decrease
    NumDays temp3 = --day;
    cout << "Prefix decrease Days 1: " << temp3.GetDays() << endl;
    return 0;
}

