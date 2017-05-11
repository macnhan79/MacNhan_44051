/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "TimeOff.h"



void TimeOff::SetUnpaidTaken(NumDays unpaidTaken) {
    this->unpaidTaken = unpaidTaken;
}

NumDays TimeOff::GetUnpaidTaken() const {
    return unpaidTaken;
}

void TimeOff::SetMaxUnpaid(NumDays maxUnpaid) {
    this->maxUnpaid = maxUnpaid;
}

NumDays TimeOff::GetMaxUnpaid() const {
    return maxUnpaid;
}

void TimeOff::SetVacTaken(NumDays vacTaken) {
    this->vacTaken = vacTaken;
}

NumDays TimeOff::GetVacTaken() const {
    return vacTaken;
}

void TimeOff::SetMaxVacation(NumDays maxVacation) {
    this->maxVacation = maxVacation;
}

NumDays TimeOff::GetMaxVacation() const {
    return maxVacation;
}

void TimeOff::SetSickTaken(NumDays sickTaken) {
    this->sickTaken = sickTaken;
}

NumDays TimeOff::GetSickTaken() const {
    return sickTaken;
}

void TimeOff::SetMaxSickDays(NumDays maxSickDays) {
    this->maxSickDays = maxSickDays;
}

NumDays TimeOff::GetMaxSickDays() const {
    return maxSickDays;
}

void TimeOff::SetId(string id) {
    this->id = id;
}

string TimeOff::GetId() const {
    return id;
}

void TimeOff::SetName(string name) {
    this->name = name;
}

string TimeOff::GetName() const {
    return name;
}