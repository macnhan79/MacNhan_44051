/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 5, 2017, 8:48 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int sizeOfPop, days;
    float increase;
    do {
        cout << "Enter the size of population: ";
        cin >> sizeOfPop;
    } while (sizeOfPop <= 2);
    do {
        cout << "Enter average daily population increase (%): ";
        cin >> increase;
    } while (increase <= 0);
    do {
        cout << "Enter the number of days they will multiply: ";
        cin >> days;
    } while (increase <= 1);
    for (int i = 0; i < days; i++) {
        sizeOfPop += sizeOfPop * (increase / 100);
    }
    cout << "The population after " << days << " days is: " << sizeOfPop << endl;
    return 0;
}

