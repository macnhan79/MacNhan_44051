/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on May 10, 2017, 1:32 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;
#include "TimeOff.h"
#include "NumDays.h"
/*
 * 
 */
bool cinValidNumber(int &);

int main(int argc, char** argv) {
    TimeOff time;
    string name, id;
    //enter name
    cout << "Enter name's employee: ";
    getline(cin, name);
    time.SetName(name);
    //enter id
    cout << "Enter ID's employee: ";
    cin.ignore();
    getline(cin, id);
    time.SetId(id);
    //max sick day
    int maxSickDay;
    do {
        do {
            cout << "Enter maximum sick days: ";
        } while (!cinValidNumber(maxSickDay));
    } while (maxSickDay <= 0);
    NumDays numMaxSickDays(maxSickDay * 8);
    time.SetMaxSickDays(numMaxSickDays);
    //sick day
    int sickDay;
    do {
        do {
            cout << "Enter sick days: ";
        } while (!cinValidNumber(sickDay));
        if (sickDay > maxSickDay)
            cout << "The number of days of sick must be smaller than maximum sick days and bigger than 0." << endl;
    } while (sickDay > maxSickDay || sickDay < 0);
    NumDays numSickDays(sickDay * 8);
    time.SetSickTaken(numSickDays);
    //max vacation day
    int maxVacationDay;
    do {
        do {
            cout << "Enter maximum vacation days: ";
        } while (!cinValidNumber(maxVacationDay));
        if (maxVacationDay > 30)
            cout << "The number of days of vacation must be greater than 0 and less than 30 days (240 hours)." << endl;
        //check maxVacationDay is not a positive number and not greater than 240 hours(30days)
    } while (maxVacationDay <= 0 || maxVacationDay > 30);
    NumDays numMaxVacationDays(maxVacationDay * 8);
    time.SetMaxVacation(numMaxVacationDays);
    //vacation day
    int vacationDay;
    do {
        do {
            cout << "Enter vacation days: ";
        } while (!cinValidNumber(vacationDay));
        if (sickDay > maxSickDay)
            cout << "The number of days of vacation must be smaller than maximum vacation days and bigger than 0." << endl;
    } while (vacationDay > maxVacationDay || vacationDay < 0);
    NumDays nuvacationDays(vacationDay * 8);
    time.SetVacTaken(nuvacationDays);
    //max unpaid day
    int maxUnpaidDay;
    do {
        do {
            cout << "Enter maximum unpaid days: ";
        } while (!cinValidNumber(maxUnpaidDay));
    } while (maxUnpaidDay <= 0);
    NumDays numMaxUnpaidDays(maxUnpaidDay * 8);
    time.SetMaxUnpaid(numMaxUnpaidDays);
    //unpaid day
    int unpaidDay;
    do {
        do {
            cout << "Enter unpaid days: ";
        } while (!cinValidNumber(unpaidDay));
        if (sickDay > maxSickDay)
            cout << "The number of days of unpaid must be smaller than maximum unpaid days and bigger than 0." << endl;
    } while (unpaidDay > maxUnpaidDay || unpaidDay < 0);
    NumDays numUnpaidDays(unpaidDay * 8);
    time.SetUnpaidTaken(numUnpaidDays);


    /////////////////////////////////////////
    //print
    cout << "-----------------------------------------------------------" << endl;
    cout << "Name: " << time.GetName() << endl;
    cout << "ID: " << time.GetId() << endl;
    cout << "Maximum sick days: " << time.GetMaxSickDays().GetDays() << endl;
    cout << "Sick days: " << time.GetSickTaken().GetDays() << endl;
    cout << "Maximum vacation days: " << time.GetMaxVacation().GetDays() << endl;
    cout << "Vacation days: " << time.GetVacTaken().GetDays() << endl;
    cout << "Maximum unpaid days: " << time.GetMaxUnpaid().GetDays() << endl;
    cout << "Unpaid days: " << time.GetUnpaidTaken().GetDays() << endl;
    return 0;
}

bool cinValidNumber(int &number) {
    float temp;
    cin >> temp;
    number = static_cast<int> (temp);
    bool isCorrect = true;
    if (cin.fail()) {

        cin.clear();
        cin.ignore(80, '\n');
        isCorrect = false;
    }
    return isCorrect;
}