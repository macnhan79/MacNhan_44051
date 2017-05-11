/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   TimeOff.h
 * Author: admin
 *
 * Created on May 10, 2017, 1:32 AM
 */

#ifndef TIMEOFF_H
#define TIMEOFF_H
#include <string>
#include "NumDays.h"
using namespace std;

class TimeOff {
private:
    string name;
    string id;
    NumDays maxSickDays;
    NumDays sickTaken;
    NumDays maxVacation;
    NumDays vacTaken;
    NumDays maxUnpaid;
    NumDays unpaidTaken;
public:
   
    void SetUnpaidTaken(NumDays unpaidTaken);

    NumDays GetUnpaidTaken() const;

    void SetMaxUnpaid(NumDays maxUnpaid);

    NumDays GetMaxUnpaid() const;

    void SetVacTaken(NumDays vacTaken);

    NumDays GetVacTaken() const;

    void SetMaxVacation(NumDays maxVacation);

    NumDays GetMaxVacation() const;

    void SetSickTaken(NumDays sickTaken);

    NumDays GetSickTaken() const;

    void SetMaxSickDays(NumDays maxSickDays);

    NumDays GetMaxSickDays() const;
    void SetId(string id);
    string GetId() const;
    void SetName(string name);
    string GetName() const;
};

#endif /* TIMEOFF_H */

