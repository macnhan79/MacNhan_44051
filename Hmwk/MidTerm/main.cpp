/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on April 18, 2017, 1:38 PM
 */

#include <cstdlib>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <math.h>
#include <cmath>
using namespace std;
#include "Employee.h"
#include "statsResult.h"
#include "customerInfo.h"
#include "Prime.h"
#include "Primes.h"

/*-----------------Prototype------------------------*/
bool cinValidNumber(int &);
bool cinValidNumber(float &);
/*Problem 1*/
void problem1();
/*---------------------------------------------*/

/*Problem 2*/
const string COMPANY_NAME = "ABC";
void problem2();
/*---------------------------------------------*/

/*Problem 3*/
void problem3();
statsResult *avgMedMode(int *, int);
float getMedian(int *, int);
void selectionSort(int *, int);
int getFre(int *, int, statsResult *);
float getMean(int *, int);
void printStat(statsResult *);
/*---------------------------------------------*/

/*Problem 4*/
void problem4();
void encryption(char *);
void decryption(char *);
/*---------------------------------------------*/

/*Problem 5*/
void problem5();
void factorial();
/*---------------------------------------------*/

/*Problem 6*/
void problem6();
void convert10tob(int, int);
void convertFloating2Hex(double);
void convertHex2Dec(char const *, int);
/*---------------------------------------------*/

/*Problem 7*/
void problem7();
bool checkPrimeNumber(int);
/*---------------------------------------------*/
void callMainMenu();

/*
 * 
 */
int main(int argc, char** argv) {
    callMainMenu();
    return 0;
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

/*Problem 1*/
void problem1() {
    int numOfCus;
    do {
        cout << "The number of customers: ";
    } while (!cinValidNumber(numOfCus));
    //create structure
    customerInfo *cus = new customerInfo[numOfCus];
    //input info of customers
    for (int i = 0; i < numOfCus; i++) {
        cout << "Enter name: ";
        cin >> cus[i].name;
        cout << "Enter address: ";
        cin >> cus[i].address;
        //enter account number
        do {
            cout << "Enter account number: ";
        } while (!cinValidNumber(cus[i].accNumber)
                || cus[i].accNumber < 10000 || cus[i].accNumber > 99999);
        //current balance
        do {
            cout << "Enter starting balance: ";
        } while (!cinValidNumber(cus[i].balance));
        //check
        int numOfChecks;
        do {
            cout << "The number of check: ";
        } while (!cinValidNumber(numOfChecks));
        cus[i].totalCheck = 0;
        for (int j = 0; j < numOfChecks; j++) {
            float check;
            do {
                cout << "Enter the amount of check " << j + 1 << ": ";
            } while (!cinValidNumber(check));
            cus[i].totalCheck += check;
        }
        //deposits
        int numOfDeposits;
        do {
            cout << "The number of deposits: ";
        } while (!cinValidNumber(numOfDeposits));
        cus[i].deposit = 0;
        for (int j = 0; j < numOfDeposits; j++) {
            float deposit = 0;
            do {
                cout << "Enter the amount of deposit " << i + 1 << ": ";
            } while (!cinValidNumber(deposit));
            cus[i].deposit += deposit;
        }
    }
    //display
    for (int i = 0; i < numOfCus; i++) {
        cout << "----------------------------------" << endl;
        cout << "Customer " << i + 1 << endl;
        cout << "Name: " << cus[i].name << endl;
        cout << "Address: " << cus[i].name << endl;
        cout << "Starting balance: " << cus[i].balance << endl;
        cout << "Total of checks: " << cus[i].totalCheck << endl;
        cout << "Total of deposits: " << cus[i].deposit << endl;
        //calc balance-----------------------
        cus[i].balance = cus[i].balance + cus[i].deposit - cus[i].totalCheck;
        if (cus[i].balance < 0) {
            cus[i].balance -= 15;
            cout << "Your account have overdraw. You will be charged $15 in your account." << endl;
            cout << "Current balance: " << cus[i].balance << endl;
        } else {
            cout << "Current balance: " << cus[i].balance << endl;
        }
    }
    //delete
    delete []cus;
}
/*---------------------------------------------*/

/*Problem 2*/
void problem2() {
    int size;
    cout << "Enter the number of employee: ";
    cin >> size;
    Employee *emp = new Employee[size];
    //input info of employee
    for (int i = 0; i < size; i++) {
        cout << "--------------------------------" << endl;
        cout << "Employee " << i + 1 << endl;
        //name
        do {
            cout << "Enter employee name: ";
            cin >> emp[i].name;
        } while (!emp[i].name.compare(""));
        //address
        do {
            cout << "Enter employee address: ";
            cin.ignore();
            getline(cin, emp[i].address);
        } while (!emp[i].address.compare(""));
        //hours worked
        do {
            cout << "Enter hours worked: ";
        } while (!cinValidNumber(emp[i].hoursWorked) && emp[i].hoursWorked < 0);
        //rate of pay
        do {
            cout << "Enter rate of pay: ";
        } while (!cinValidNumber(emp[i].rateOfPay) && emp[i].rateOfPay < 0);

        //calc payment
        //hours worked  > 0 and <= 40
        if (emp[i].hoursWorked <= 40) {
            emp[i].totalPay = emp[i].hoursWorked * emp[i].rateOfPay;
        }//hours worked >40 and <= 50
        else if (emp[i].hoursWorked > 40 && emp[i].hoursWorked <= 50) {
            int extraHours = emp[i].hoursWorked - 40;
            emp[i].totalPay = emp[i].rateOfPay * 40 + emp[i].rateOfPay * extraHours * 2;
        }//hours worked > 50
        else {
            int extraHours = emp[i].hoursWorked - 50;
            emp[i].totalPay = emp[i].rateOfPay * 40 + 2 * emp[i].rateOfPay * 10 + 3 * emp[i].rateOfPay*extraHours;
        }
    }

    //print pay check
    for (int i = 0; i < size; i++) {
        cout << "--------------------------------" << endl;
        cout << "Paycheck" << endl;
        cout << "Company: " << COMPANY_NAME << endl;
        cout << "Address: " << emp[i].address << endl;
        cout << "Name: " << emp[i].name << endl;
        cout << "Amount: " << emp[i].totalPay << endl;
        cout << "Signature: " << endl;
    }
    delete []emp;
}
/*---------------------------------------------*/

/*Problem 3*/
void problem3() {
    int size;
    cout << "Enter size of array: ";
    cin >> size;
    int *array = new int[size];
    for (int i = 0; i < size; i++) {
        do {
            cout << "Enter element " << i + 1 << ": ";
        } while (!cinValidNumber(array[i]));
    }
    statsResult *result = avgMedMode(array, size);
    printStat(result);
    //delete
    delete []result->mode;
    delete result;
    delete []array;
}

statsResult *avgMedMode(int *arr, int size) {
    statsResult *result = new statsResult;
    selectionSort(arr, size);
    int modeNumber;
    result->maxFreq = getFre(arr, size, result);
    result->median = getMedian(arr, size);
    result->avg = getMean(arr, size);
    return result;
}

void printStat(statsResult *result) {

    cout << "Frequency: " << result->maxFreq << endl;
    cout << "Median: " << result->median << endl;
    cout << "Mean: " << result->avg << endl;
    cout << "Mode number: ";
    //    
    for (int i = 0; i < result->nModes; i++) {
        cout << result->mode[i];
        if (i != result->nModes - 1)
            cout << ",";
    }
    cout << endl;
    //delete result;
}

float getMean(int array[], int size) {
    float total;
    for (int i = 0; i < size; i++) {
        total += *(array + i);
    }
    return static_cast<float> (total) / size;
}

float getMedian(int array[], int size) {
    if (size % 2 == 1) {
        return static_cast<float> (*(array + (size - 1) / 2));
    } else {
        return (static_cast<float> (*(array + (size - 2) / 2)) + *(array + size / 2)) / 2;
    }
}

int getFre(int array[], int size, statsResult *result) {
    //  int &modenumber, int *arrMode
    int countOld = 1, countNew = 0;
    int beginNum = *(array);
    vector<int> vArrMode;
    for (int i = 1; i < size; i++) {
        if (beginNum == *(array + i)) {
            beginNum = *(array + i);
            countOld++;
        } else {
            if (countOld >= 2) {
                vArrMode.push_back(beginNum);
            }
            beginNum = *(array + i);

            if (countOld > countNew) {

                //cout << *(array + i - 1) << endl;
                //result->nModes = *(array + i - 1);
                //vArrMode.push_back(*(array + i - 1));
                countNew = countOld;

            }
            countOld = 1;
        }
        if (i == (size - 1)) {
            if (countOld >= 2) {
                vArrMode.push_back(beginNum);
            }
            beginNum = *(array + i);

            if (countOld > countNew) {

                //cout << *(array + i - 1) << endl;
                //result->nModes = *(array + i - 1);
                //vArrMode.push_back(*(array + i - 1));
                countNew = countOld;
                countOld = 1;
            }
        }
    }
    result->nModes = vArrMode.size();
    result->mode = new int[vArrMode.size()];
    for (int i = 0; i < vArrMode.size(); i++) {
        result->mode[i] = vArrMode[i];
    }
    if (countNew == 1)
        return -1;
    else
        return countNew;
}

void selectionSort(int array[], int size) {
    int startScan, minIndex, minValue;

    for (startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minValue = *(array + startScan);
        for (int index = startScan + 1; index < size; index++) {
            if (*(array + index) < minValue) {
                minValue = *(array + index);
                minIndex = index;
            }
        }
        *(array + minIndex) = *(array + startScan);
        *(array + startScan) = minValue;
    }
}


/*---------------------------------------------*/

/*Problem 4*/
void problem4() {
    char c[4];
    bool validNumber = true;
    do {
        validNumber = true;
        cout << "Enter four-digit integers: ";
        cin >> c;
        //check valid number
        for (int i = 0; i < 4; i++) {
            switch (c[i]) {
                case '0':
                case '1':
                case '2':
                case '3':
                case '4':
                case '5':
                case '6':
                case '7':
                    continue;
                default:
                    validNumber = false;
            }
            if (!validNumber) {
                cout << "Four-digit integer should be the numbers 0 to 7." << endl;
                break;
            }
        }
    } while (!validNumber);
    encryption(c);
    cout << "The encrypted integer: " << c << endl;
    decryption(c);
    cout << "The decrypted integer: " << c << endl;
}

void encryption(char *c) {
    //encrypt number
    for (int i = 0; i < 4; i++) {
        // ????????????????????????????????????????
        int number = c[i] - '0';
        int nEncrypt = (number + 3) % 8;
        //cout << nEncrypt << endl;
        char const *cTemp = to_string(nEncrypt).c_str();
        //cout << cTemp << endl;
        c[i] = *cTemp;
    }
    //swap number
    swap(c[0], c[1]);
    swap(c[2], c[3]);
    //cout << cEncrypt << endl;
}

void decryption(char *c) {
    for (int i = 0; i < 4; i++) {
        int number = c[i] - '0';
        // (numberBeforeEncrypt + 3)%8 = numberAfterEncrypt
        // (numberBeforeEncrypt + 3) - (numberBeforeEncrypt + 3)/8 * 8 = numberAfterEncrypt
        // numberBeforeEncrypt is alway < 8 so (numberBeforeEncrypt + 3)/8 = 1
        // (numberBeforeEncrypt + 3) - 1 * 8 = numberAfterEncrypt
        // (numberBeforeEncrypt + 3) = numberAfterEncrypt + 8
        // numberBeforeEncrypt = numberAfterEncrypt + 8 - 3
        //numberBeforeEncrypt = numberAfterEncrypt + 5
        //numberBeforeEncrypt = (numberAfterEncrypt + 5)%8
        //    int encrytion = (5 + 3) % 8;
        int nDecrypt = (5 + number) % 8;
        //cout << nEncrypt << endl;
        char const *cTemp = to_string(nDecrypt).c_str();
        //cout << cTemp << endl;
        c[i] = *cTemp;
    }
    //swap number
    swap(c[0], c[1]);
    swap(c[2], c[3]);
    //cout << cEncrypt << endl;
}

/*---------------------------------------------*/

/*Problem 5*/
void problem5() {
    cout << "5! is the highest for a character" << endl;
    cout << "7! is the highest for a short" << endl;
    cout << "12! is the highest for an integer" << endl;
    cout << "12! is the highest for an unsigned integer" << endl;
    cout << "20! is the highest for a long" << endl;
    cout << "20! is the highest for a unsigned long" << endl;
    cout << "170! is the highest for a double" << endl;
    cout << "34! is the highest for a float" << endl;
    cout << "1755! is the highest for a long double" << endl;
    //    unsigned int a = 1;
    //    factorial();
}

void factorial() {
    int a = 1;
    bool over = false;
    for (int j = 0; j < 2000; j++) {
        double b = 1;
        for (int i = 1; i <= a; i++) {
            //            if ((b * i) <= 0 || (b * i) == INFINITY) {
            //                over = true;
            //            }
            b = b * i;
        }
        if (over) {
            break;
        }
        cout << a << "! = " << b << endl;
        a = a + 1;
    }
}
/*---------------------------------------------*/

/*Problem 6*/
void problem6() {
    //convert10tob(27, 2);
    cout << "2.325 (base 10) is ";
    convertFloating2Hex(2.325);
    cout << " base 16" << endl;
    //
    cout << "0.1453125 (base 10) is ";
    convertFloating2Hex(0.1453125);
    cout << " base 16" << endl;
    //
    string hex = "59999901";
    cout << hex << " (base 16) is ";
    convertHex2Dec(hex.c_str(), hex.length());
    cout << " base 10" << endl;
    //
    hex = "59999902";
    cout << hex << " (base 16) is ";
    convertHex2Dec(hex.c_str(), hex.length());
    cout << " base 10" << endl;
    //
    hex = "A66667FE";
    cout << hex << " (base 16) is ";
    convertHex2Dec(hex.c_str(), hex.length());
    cout << " base 10" << endl;
}

void convertHex2Dec(char const *c, int size) {
    float decimal = 0;
    int tempSize = size;
    for (int i = 0; i < size; i++) {
        switch (c[i]) {
            case 'A':
                decimal = decimal + 10 * pow(16, tempSize - 1);
                break;
            case 'B':
                decimal = decimal + 11 * pow(16, tempSize - 1);
                break;
            case 'C':
                decimal = decimal + 12 * pow(16, tempSize - 1);
                break;
            case 'D':
                decimal = decimal + 13 * pow(16, tempSize - 1);
                break;
            case 'E':
                decimal = decimal + 14 * pow(16, tempSize - 1);
                break;
            case 'F':
                decimal = decimal + 15 * pow(16, tempSize - 1);
                break;
            default:
                char const cTemp = c[i];
                decimal = decimal + atoi(&cTemp) * pow(16, tempSize - 1);
        }
        tempSize--;
    }
    cout << decimal;
}

void convertFloating2Hex(double number) {
    double intpart;
    double fractpart = modf(number, &intpart);
    int temp = intpart;
    convert10tob(temp, 16);
    cout << ".";
    while (fractpart != 0) {
        double d = fractpart * 16;
        fractpart = modf(d, &intpart);
        convert10tob(intpart, 16);
    }
}

void convert10tob(int number, int base) {
    if (number == 0)
        return;
    int x = number % base;
    number /= base;
    if (x < 0)
        number += 1;
    convert10tob(number, base);
    if (x < 0) {
        int temp = x + (base * -1);
        cout << temp;
    } else {
        if (base == 16 && x > 9) {
            switch (x) {
                case 10:
                    cout << "A";
                    break;
                case 11:
                    cout << "B";
                    break;
                case 12:
                    cout << "C";
                    break;
                case 14:
                    cout << "D";
                    break;
                case 15:
                    cout << "E";
                    break;
                case 16:
                    cout << "F";
                    break;
            }
        } else {
            cout << x;
        }

    }
    //cout<< (x < 0) ? (x + (b * -1)) : x;
    return;
}
/*---------------------------------------------*/

/*Problem 7*/
void problem7() {
    Prime prime;
    Primes primes;
    vector<int> primeFactors;
    int number;
    do {
        do {
            do {
                cout << "Enter a number [101-10000]: ";
            } while (!cinValidNumber(number));
        } while (checkPrimeNumber(number));
    } while (number < 100 || number > 10000);

    for (int i = 2; i <= number; i++) {
        bool isPrime = checkPrimeNumber(i);
        if (isPrime && number % i == 0) {
            number /= i;
            primeFactors.push_back(i);
            i--;
        }
        if (number == 1) {
            break;
        }
    }
    for (int i = 0; i < primeFactors.size(); i++) {
        cout << primeFactors[i];
        if (i != primeFactors.size() - 1) {
            cout << " x ";
        }
    }
    cout << endl;
    //    primes.nPrimes = '1';
    //    prime.power = '1';
    //    prime.prime = primeFactors[0] - '0';
    //    primes.prime = new Prime[primeFactors.size()];
    //    int currentPower = 1;
    //    int nPrime = 1;
    //    for (int i = 1; i < primeFactors.size(); i++) {
    //        if (primeFactors[i] == primeFactors[i - 1]) {
    //            currentPower++;
    //            char const *cTemp = to_string(currentPower).c_str();
    //            prime.power = *cTemp;
    //        } else {
    //            char const *cTemp = to_string(primeFactors[i]).c_str();
    //            prime.prime = *cTemp;
    //            prime.power = '1';
    //            currentPower = 1;
    //            char const *cTempNPrime = to_string(nPrime).c_str();
    //            primes.nPrimes = *cTempNPrime;
    //            nPrime++;
    //        }
    //    }
    //    int size = primes.nPrimes - '0';
    //    for (int i = 0; i < size; i++) {
    //        cout << primes.prime[i].prime - '0' << "^" << primes.prime[i].power - '0' << endl;
    //    }
}

bool checkPrimeNumber(int number) {
    bool isPrime = true;
    //loop to number/2
    for (int i = 2; i < number / 2; i++) {
        if (number % i == 0) {
            isPrime = false;
            break;
        }
    }
    return isPrime;
}

/*---------------------------------------------*/


void callMainMenu() {
    int choice = -1;
    //loop while choice is correct
    do {
        //print list of choice
        do {
            cout << "1. Problem 1." << endl;
            cout << "2. Problem 2." << endl;
            cout << "3. Problem 3." << endl;
            cout << "4. Problem 4." << endl;
            cout << "5. Problem 5." << endl;
            cout << "6. Problem 6." << endl;
            cout << "7. Problem 7." << endl;
            cout << "Enter your choice: ";
        } while (!cinValidNumber(choice));
    } while (choice < 1 || choice > 7);
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
            break;
        default:
            cout << "Press [Enter] to continue...";
            cin.ignore();
            cin.get();
            callMainMenu();
    }
}