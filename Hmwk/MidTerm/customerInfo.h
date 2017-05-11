/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   customerInfo.h
 * Author: rcc
 *
 * Created on April 18, 2017, 1:41 PM
 */

#ifndef CUSTOMERINFO_H
#define CUSTOMERINFO_H
#include <string>

struct customerInfo {
    string name;
    string address;
    int accNumber; /*! Five digits only, i.e. test for this */
    float balance; //<! Balance at the beginning of the month 
    float totalCheck; //<! Total of all checks written by this customer this month
    float deposit; //<! Total of all deposits credited to this customer's account this month
};


#endif /* CUSTOMERINFO_H */

