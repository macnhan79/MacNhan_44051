/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 5, 2017, 7:49 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int month, year;
    cout << "Enter a month (1-12): ";
    cin >> month;
    cout << "Enter a year: ";
    cin >> year;
    if (month == 2) {
        if ((year % 100 == 0) && (year % 400 == 0))
            cout << "29 days" << endl;
        else if (year % 4 == 0)
            cout << "29 days" << endl;
        else
            cout << "28 days" << endl;
    } else {
        switch (month) {
            case 1:case 3:case 5:case 7:case 8:case 10:case 12:
                cout << "31 days" << endl;
                break;
            case 4: case 6: case 9:case 11:
                cout << "30 days" << endl;
                break;
            default:
                cout << "Not a month" << endl;
        }
    }
    return 0;
}

