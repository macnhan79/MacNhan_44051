/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 5, 2017, 7:24 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float celTemp, fahTemp;
    cout << "Enter Celsius temperatures: ";
    cin >> celTemp;
    fahTemp = (9.0 / 5.0) * celTemp+32;
    cout << "Fahrenheit temperatures is: " << fahTemp << endl;
    return 0;
}

