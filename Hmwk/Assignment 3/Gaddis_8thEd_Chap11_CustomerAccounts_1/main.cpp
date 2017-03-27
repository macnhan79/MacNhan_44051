/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 24, 2017, 4:29 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "CustomerAccount.h"
/*
 * 
 */
void inputData(CustomerAccount *);
void displayData(CustomerAccount *);
void changeData(CustomerAccount *);
void inputAnCustomer(CustomerAccount &);
void callMenu(CustomerAccount *);
void searchAndDisplay(CustomerAccount *, string);
bool cinValidNumber(int &);
bool cinValidNumber(float &);
const int SIZE = 12;

int main(int argc, char** argv) {
    CustomerAccount *c = new CustomerAccount[SIZE];
    callMenu(c);
    return 0;
}

void callMenu(CustomerAccount *c) {
    int choice = -1;
    do {
        do {
            cout << "1. Enter data into the array." << endl;
            cout << "2. Change the content." << endl;
            cout << "3. Display all the data." << endl;
            cout << "4. Search customers." << endl;
            cout << "Enter your choice: ";
        } while (!cinValidNumber(choice));
    } while (choice < 1 || choice > 4);
    cout << "-------------------------------" << endl;
    switch (choice) {
        case 1: inputData(c);
            break;
        case 2: changeData(c);
            break;
        case 3: displayData(c);
            break;
        case 4:
            string name;
            cout << "Enter customer name: ";
            cin >> name;
            searchAndDisplay(c, name);
            break;
    }
}

void inputData(CustomerAccount *c) {
    for (int i = 0; i < SIZE; i++) {
        cout << "\tCustomer " << i + 1 << endl;
        inputAnCustomer(c[i]);
    }
    callMenu(c);
}

void displayData(CustomerAccount *c) {
    for (int i = 0; i < SIZE; i++) {
        cout << "Name of customer: " << c[i].name << endl;
        cout << "Address of customer: " << c[i].address << endl;
        cout << "City of customer: " << c[i].city << endl;
        cout << "State of customer: " << c[i].state << endl;
        cout << "Zip of customer: " << c[i].zip << endl;
        cout << "Telephone of customer: " << c[i].telephoneNumber << endl;
        cout << "Balance of customer: " << c[i].accountBalance << endl;
        cout << "Data of last payment: " << c[i].dateLastPayment << endl;
        cout << "---------------------------------------" << endl;
    }
    callMenu(c);
}

void changeData(CustomerAccount *c) {
    int index;
    do {
        do {
            cout << "Enter index (0 to 11): ";
        } while (!cinValidNumber(index));
    } while (index < 0 || index > 11);
    inputAnCustomer(c[index]);
    callMenu(c);
}
//fix--------------?????????????????????????????

void inputAnCustomer(CustomerAccount &c) {
//name
    do {
        cout << "Enter name of customer: ";
        cin.ignore();
        getline(cin, c.name);
    } while (!c.name.compare(""));
    //address
    do {
        cout << "Enter address of customer: ";
        getline(cin, c.address);
    } while (!c.address.compare(""));
    //city
    do {
        cout << "Enter city of customer: ";
        getline(cin, c.city);
    } while (!c.city.compare(""));
    //state
    do {
        cout << "Enter state of customer: ";
        getline(cin, c.state);
    } while (!c.state.compare(""));
    //zipcode
    do {
        cout << "Enter zip code of customer: ";
    } while (!cinValidNumber(c.zip));
    //telephone
    do {
        cout << "Enter telephone number of customer: ";
        getline(cin, c.telephoneNumber);
    } while (!c.telephoneNumber.compare(""));
    //balance
    do {
        do {
            cout << "Enter balance of customer: ";
        } while (!cinValidNumber(c.accountBalance));
    } while (c.accountBalance < 0);
    //date
    do {
        cout << "Enter date of last payment: ";
        getline(cin, c.dateLastPayment);
    } while (!c.dateLastPayment.compare(""));
}

void searchAndDisplay(CustomerAccount *c, string name) {
    int counter = 0;
    for (int i = 0; i < SIZE; i++) {
        if (!c[i].name.compare(name)) {
            cout << "Name of customer: " << c[i].name << endl;
            cout << "Address of customer: " << c[i].address << endl;
            cout << "City of customer: " << c[i].city << endl;
            cout << "State of customer: " << c[i].state << endl;
            cout << "Zip of customer: " << c[i].zip << endl;
            cout << "Telephone of customer: " << c[i].telephoneNumber << endl;
            cout << "Balance of customer: " << c[i].accountBalance << endl;
            cout << "Data of last payment: " << c[i].dateLastPayment << endl;
            cout << "---------------------------------------" << endl;
            counter++;
        }
    }
    if (counter == 0)
        cout << "Not found customer: " << name << endl;
    callMenu(c);
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

bool cinValidNumber(float &number) {
    cin >> number;
    bool isCorrect = true;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(80, '\n');
        isCorrect = false;
    }
    return isCorrect;
}