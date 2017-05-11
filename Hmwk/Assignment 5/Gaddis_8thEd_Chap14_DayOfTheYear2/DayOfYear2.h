/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DayOfYear2.h
 * Author: admin
 *
 * Created on May 9, 2017, 10:30 PM
 */

#ifndef DAYOFYEAR2_H
#define DAYOFYEAR2_H

#include <string>
#include <iostream>
using namespace std;

class DayOfYear2 {
    unsigned int days;
    string month;
    int dayOfMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
public:
    DayOfYear2(unsigned int, string);

    void SetMonth(string);

    string GetMonth() const;

    void SetDays(unsigned int);

    unsigned int GetDays() const;

    void print();

    int displayMonth();

};

#endif /* DAYOFYEAR2_H */

