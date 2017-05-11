/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on May 10, 2017, 1:48 PM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "Car.h"
#include "Date.h"
#include "DayOfYear.h"
#include "DayOfYear2.h"
#include "Employee.h"
#include "NumDays.h"
#include "Numbers.h"
#include "PersonalInfo.h"
#include "RetailItem.h"
#include "TimeOff.h"

using namespace std;
/*Problem 1*/
void problem1();
/*---------------------------------------------*/

/*Problem 2*/
void problem2();
/*---------------------------------------------*/
/*Problem 3*/
void problem3();
/*---------------------------------------------*/

/*Problem 4*/
void problem4();
/*---------------------------------------------*/
/*Problem 5*/
void problem5();
/*---------------------------------------------*/

/*Problem 6*/
void problem6();
/*---------------------------------------------*/
/*Problem 7*/
void problem7();
/*---------------------------------------------*/

/*Problem 8*/
void problem8();
/*---------------------------------------------*/
/*Problem 9*/
void problem9();
/*---------------------------------------------*/

/*Problem 10*/
void problem10();
/*---------------------------------------------*/
void callMainMenu();
bool cinValidNumber(int &);
bool cinValidNumber(unsigned int &);

/*
 * 
 */
int main(int argc, char** argv) {
    callMainMenu();
    return 0;
}

void problem1() {
    Car car(2017, "Honda");
    //increase speed
    car.accelerate();
    car.accelerate();
    car.accelerate();
    car.accelerate();
    car.accelerate();
    //brake
    car.brake();
    car.brake();
    car.brake();
    car.brake();
    car.brake();
    //print speed
    cout << "Current speed: " << car.GetSpeed() << endl;
}

void problem2() {
    Date date;
    int day, month, year;
    //input day
    do {
        do {
            cout << "Enter day: ";
        } while (!cinValidNumber(day));
    } while (day > 31 || day < 1);
    date.SetDay(day);
    //input month
    do {
        do {
            cout << "Enter month: ";
        } while (!cinValidNumber(month));
    } while (month > 12 || month < 1);
    date.SetMonth(month);
    //input year
    do {
        cout << "Enter year: ";
    } while (!cinValidNumber(year));
    date.SetYear(year);
    //print output
    date.Print_dd_m_yy();
    date.Print_m_dd_yyyy();
    date.Print_mm_dd_yyyy();
}

void problem3() {
    Employee *emp = new Employee[3];
    //input employee 1
    emp[0].SetName("Susan Meyers");
    emp[0].SetIdNumber(47899);
    emp[0].SetDepartment("Accouting");
    emp[0].SetPosition("Vice President");
    //input employee 2
    emp[1].SetName("Mark Jones");
    emp[1].SetIdNumber(39119);
    emp[1].SetDepartment("IT");
    emp[1].SetPosition("Programmer");
    //input employee 3
    emp[2].SetName("Joy Rogers");
    emp[2].SetIdNumber(81774);
    emp[2].SetDepartment("Manufacturing");
    emp[2].SetPosition("Engineer");
    //print employee
    cout << "Name\t\tID number\t\tDepartment\t\tPosition" << endl;
    cout << "--------------------------------------------------------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << emp[i].GetName() << "\t\t"
                << emp[i].GetIdNumber() << "\t\t"
                << emp[i].GetDepartment() << "\t\t"
                << emp[i].GetPosition() << endl;
    }
    //delete employee
    delete []emp;
}

void problem4() {
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
}

void problem5() {
    //init
    RetailItem r1("Jacket", 12, 59.95);
    RetailItem r2("Designer Jeans", 40, 34.95);
    RetailItem r3("Shirt", 20, 24.95);
    //print
    cout << "\tDescription\tUnits On Hand\tPrice" << endl;
    cout << "Item #1\t" << r1.GetDescription()
            << "\t\t" << r1.GetUnitsOnHand()
            << "\t\t" << r1.GetPrice() << endl;
    cout << "Item #2\t" << r2.GetDescription()
            << "\t" << r2.GetUnitsOnHand()
            << "\t\t" << r2.GetPrice() << endl;
    cout << "Item #3\t" << r3.GetDescription()
            << "\t\t" << r3.GetUnitsOnHand()
            << "\t\t" << r3.GetPrice() << endl;
}

void problem6() {
    unsigned int day;
    do {
        do {
            cout << "Enter days: ";
        } while (!cinValidNumber(day));
    } while (day > 365);
    DayOfYear days(day);
    days.print();
}

void problem7() {
    unsigned int day;
    string month;
    do {
        cout << "Enter days: ";
    } while (!cinValidNumber(day));
    //input month
    cin.ignore();
    cout << "Enter month: ";
    getline(cin, month);
    DayOfYear2 day2(day, month);
    day2.print();
}

void problem8() {
    unsigned int number;
    do {
        do {
            cout << "Enter a number [0-9999]: ";
        } while (!cinValidNumber(number));
    } while (number > 9999);
    Numbers num(number);
    num.print(num.GetNumber());
    cout << endl;
}

void problem9() {
    NumDays day(12);
    NumDays day2(24);
    NumDays day3(24);

    cout << "Days 1: " << day.GetDays() << endl;
    cout << "Days 2: " << day2.GetDays() << endl;
    cout << "Days 3: " << day3.GetDays() << endl;

    //add operator
    cout << "Days 1 + 2: " << day.operator+(day2).GetDays() << endl;
    //sub operator
    cout << "Days 3 - 1: " << day3.operator-(day).GetDays() << endl;
    //prefix increase
    NumDays temp = day++;
    cout << "Postfix increase Days 1: " << temp.GetDays() << endl;
    //postfix increase
    NumDays temp1 = ++day;
    cout << "Prefix increase Days 1: " << temp1.GetDays() << endl;
    //prefix decrease
    NumDays temp2 = day--;
    cout << "Postfix decrease Days 1: " << temp2.GetDays() << endl;
    //postfix decrease
    NumDays temp3 = --day;
    cout << "Prefix decrease Days 1: " << temp3.GetDays() << endl;
}

void problem10() {
    TimeOff time;
    string name, id;
    //enter name
    cout << "Enter name's employee: ";
    cin.ignore();
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
}

/*!
 * \brief Checking the input from user. Only check integer data type.
 * \param number store the input from user
 * \return none
 */
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

bool cinValidNumber(unsigned int &number) {
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

void callMainMenu() {
    int choice = -1;
    //loop while choice is correct
    do {
        //print list of choice
        do {
            cout << "1. Problem 1(Chapter_13_Car)." << endl;
            cout << "2. Problem 2(Chapter_13_Date)." << endl;
            cout << "3. Problem 3(Chapter_13_Employee)." << endl;
            cout << "4. Problem 4(Chapter_13_Personal_Information)." << endl;
            cout << "5. Problem 5(Chapter_13_RetailItem)." << endl;
            cout << "6. Problem 6(Chapter_14_DayOfYear)." << endl;
            cout << "7. Problem 7(Chapter_14_DateOfYear2)." << endl;
            cout << "8. Problem 8(Chapter_14_NumberClass)." << endl;
            cout << "9. Problem 9(Chapter_14_NumDaysClass)." << endl;
            cout << "10. Problem 10(Chapter_14_TimeOff)." << endl;
            cout << "Enter your choice: ";
        } while (!cinValidNumber(choice));
    } while (choice < 1 || choice > 10);
    switch (choice) {

        case 1:
            problem1();
            cin.ignore();
            cout << "Press [Enter] to continue...";
            cin.get();
            callMainMenu();
            break;
        case 2:
            problem2();
            cin.ignore();
            cout << "Press [Enter] to continue...";
            cin.get();
            callMainMenu();
            break;
        case 3:
            problem3();
            cin.ignore();
            cout << "Press [Enter] to continue...";
            cin.get();
            callMainMenu();
            break;
        case 4:
            problem4();
            cin.ignore();
            cout << "Press [Enter] to continue...";
            cin.get();
            callMainMenu();
            break;
        case 5:
            problem5();
            cin.ignore();
            cout << "Press [Enter] to continue...";
            cin.get();
            callMainMenu();
            break;
        case 6:
            problem6();
            cin.ignore();
            cout << "Press [Enter] to continue...";
            cin.get();
            callMainMenu();
            break;
        case 7:
            problem7();
            cin.ignore();
            cout << "Press [Enter] to continue...";
            cin.get();
            callMainMenu();
        case 8:
            problem8();
            cin.ignore();
            cout << "Press [Enter] to continue...";
            cin.get();
            callMainMenu();
        case 9:
            problem9();
            cin.ignore();
            cout << "Press [Enter] to continue...";
            cin.get();
            callMainMenu();
        case 10:
            problem10();
            cin.ignore();
            cout << "Press [Enter] to continue...";
            cin.get();
            callMainMenu();
            break;
        default:
            cout << "Press [Enter] to continue...";
            cin.ignore();
            cin.get();
            callMainMenu();
    }
}
