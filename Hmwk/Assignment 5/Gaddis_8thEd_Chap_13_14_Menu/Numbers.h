/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Numbers.h
 * Author: rcc
 *
 * Created on May 9, 2017, 1:31 PM
 */

#ifndef NUMBERS_H
#define NUMBERS_H

#include <string>
#include <iostream>
using namespace std;

class Numbers {
private:
    unsigned int number;
    static string lessThan20[20];
    static string tens[10];
    static string hundred;
    static string thousand;
public:
    Numbers(unsigned int);

    void SetNumber(int number);

    int GetNumber() const;

    void print(int);
};

#endif /* NUMBERS_H */

