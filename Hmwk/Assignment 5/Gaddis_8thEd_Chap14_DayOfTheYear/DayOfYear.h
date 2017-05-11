/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   DayOfYear.h
 * Author: admin
 *
 * Created on May 9, 2017, 9:49 PM
 */

#ifndef DAYOFYEAR_H
#define DAYOFYEAR_H

#include <string>
#include <math.h>
#include <iostream>
using namespace std;

class DayOfYear {
private:
    unsigned int days;

public:
    
    static string month;
    
    DayOfYear(unsigned int);

    void SetDays(unsigned int);

    unsigned int GetDays() const;

    void print();

    string displayMonth(int);
};

#endif /* DAYOFYEAR_H */

