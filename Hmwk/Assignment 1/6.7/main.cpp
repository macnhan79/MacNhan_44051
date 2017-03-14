/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 6, 2017, 8:48 PM
 */

#include <iostream>

using namespace std;

/*
 * 
 */
float celsius(float fTemperature) {
    return 5.0 / 9.0 * (fTemperature - 32.0);
}

int main(int argc, char** argv) {
    cout << "Fehrenheit\tCelsius" << endl;
    for (int i = 0; i <= 20; i++) {
        cout << i << "\t\t" << celsius(i) << endl;
    }

    return 0;
}

