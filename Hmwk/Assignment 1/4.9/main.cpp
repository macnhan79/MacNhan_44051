/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 6, 2017, 8:08 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int coin2Dollar, total = 0;
    int penny, nickel, dime, quarter;
    cout << "How many coins required to make a dollar: ";
    cin >> coin2Dollar;
    cout << "Enter pennies: ";
    cin >> penny;
    cout << "Enter nickels: ";
    cin >> nickel;
    cout << "Enter dimes: ";
    cin >> dime;
    cout << "Enter quarters: ";
    cin >> quarter;
    for (int i = 0; i < penny; i++) {
        total += 1;
    }
    for (int i = 0; i < nickel; i++) {
        total += 5;
    }
    for (int i = 0; i < dime; i++) {
        total += 10;
    }
    for (int i = 0; i < quarter; i++) {
        total += 25;
    }
    if (total == coin2Dollar) {
        cout << "Win!" << endl;
    } else if (total < coin2Dollar) {
        cout << "Game over! Your coins are " << total << " less than " << coin2Dollar << endl;
    } else if (total > coin2Dollar) {
        cout << "Game over! Your coins are " << total << " more than " << coin2Dollar << endl;
    }
    return 0;
}

