/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on May 3, 2017, 12:12 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "PersonalInfo.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //init PersonalInfo
    PersonalInfo me;
    PersonalInfo friends;
    PersonalInfo family;
    //input data
    me.SetAddress("1137 Pondhurst way");
    me.SetAge(24);
    me.SetName("Nhan T Mac");
    me.SetPhoneNumber("9512318624");
    //friend
    friends.SetAddress("1820 University Ave");
    friends.SetAge(24);
    friends.SetName("Trung V Nguyen");
    friends.SetPhoneNumber("9515862482");
    //family
    family.SetAddress("Trung T Mac");
    family.SetAge(24);
    family.SetName("Trung T Mac");
    family.SetPhoneNumber("9512754187");
    //print
    cout << "My information:" << endl;
    cout << "Name: " << me.GetName() << endl;
    cout << "Age: " << me.GetAge() << endl;
    cout << "Address: " << me.GetAddress() << endl;
    cout << "Phone number: " << me.GetPhoneNumber() << endl;
    //friend
    cout << "Friend's information:" << endl;
    cout << "Name: " << friends.GetName() << endl;
    cout << "Age: " << friends.GetAge() << endl;
    cout << "Address: " << friends.GetAddress() << endl;
    cout << "Phone number: " << friends.GetPhoneNumber() << endl;
    //family
    cout << "Family's information:" << endl;
    cout << "Name: " << family.GetName() << endl;
    cout << "Age: " << family.GetAge() << endl;
    cout << "Address: " << family.GetAddress() << endl;
    cout << "Phone number: " << family.GetPhoneNumber() << endl;
    return 0;
}

