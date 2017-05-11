/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Date.h
 * Author: rcc
 *
 * Created on May 2, 2017, 2:25 PM
 */

#ifndef DATE_H
#define DATE_H
#include <string>
using namespace std;

class Date {
private:
    int month;
    int day;
    int year;


public:
    void SetYear(int);
    int GetYear() const;
    void SetDay(int);
    int GetDay() const;
    void SetMonth(int);
    int GetMonth() const;
    /*
     * Format 12/25/2017
     */
    void Print_mm_dd_yyyy();
    /*
     * Format December 25 2017
     */
    void Print_m_dd_yyyy();
    /*
     * Format 25 December 2017
     */
    void Print_dd_m_yy();
    string displayMonth(int);
};

#endif /* DATE_H */

