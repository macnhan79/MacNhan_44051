/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 5, 2017, 7:27 PM
 */

#include <cstdlib>
#include <iostream>
#include <iomanip>
using namespace std;

/*
 * 
 */
const float dollar2Yen = 113.78;
const float dollar2Euros = 0.94;
int main(int argc, char** argv) {
    float dollar;
    cout << "Enter U.S. dollar amount: ";
    cin >> dollar;
    cout << "Euros: " << setprecision(2) << fixed << dollar * dollar2Euros << endl;
    cout << "Japanese yen: " << setprecision(2) << fixed << dollar * dollar2Yen << endl;
    return 0;
}

