/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   PersonalInfo.h
 * Author: admin
 *
 * Created on May 3, 2017, 12:54 AM
 */

#ifndef PERSONALINFO_H
#define PERSONALINFO_H
#include <string>
using namespace std;

class PersonalInfo {
private:
    string name;
    string address;
    int age;
    string phoneNumber;

public:
    void SetPhoneNumber(string);

    string GetPhoneNumber() const;

    void SetAddress(string);

    string GetAddress() const;

    void SetName(string);

    string GetName() const;

    void SetAge(int age);

    int GetAge() const;

};


#endif /* PERSONALINFO_H */

