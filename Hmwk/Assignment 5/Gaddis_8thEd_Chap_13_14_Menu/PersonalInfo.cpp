/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "PersonalInfo.h"

void PersonalInfo::SetPhoneNumber(string phoneNumber) {
    this->phoneNumber = phoneNumber;
}

string PersonalInfo::GetPhoneNumber() const {
    return phoneNumber;
}

void PersonalInfo::SetAddress(string address) {
    this->address = address;
}

string PersonalInfo::GetAddress() const {
    return address;
}

void PersonalInfo::SetName(string name) {
    this->name = name;
}

string PersonalInfo::GetName() const {
    return name;
}

void PersonalInfo::SetAge(int age) {
    this->age = age;
}

int PersonalInfo::GetAge() const {
    return age;
}