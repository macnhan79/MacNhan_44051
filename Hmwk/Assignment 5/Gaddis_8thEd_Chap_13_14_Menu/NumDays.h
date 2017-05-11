/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   NumDays.h
 * Author: admin
 *
 * Created on May 9, 2017, 11:33 PM
 */

#ifndef NUMDAYS_H
#define NUMDAYS_H

#include <string>
using namespace std;

class NumDays {
private:
    int hours;
    float days;
public:
    NumDays();
    NumDays(int);

    float GetDays() const;

    void SetHours(int hours);

    int GetHours() const;

    NumDays operator+(const NumDays &);
    NumDays operator-(const NumDays &);
    NumDays operator++();
    NumDays operator++(int);
    NumDays operator--();
    NumDays operator--(int);
};

#endif /* NUMDAYS_H */

