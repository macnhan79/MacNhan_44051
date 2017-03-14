/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 6, 2017, 8:24 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    float weight, height;
    float vBMI;
    do {
        cout << "Enter your weight (pounds): ";
        cin >> weight;
    } while (weight < 0);
    do {
        cout << "Enter your height (inches): ";
        cin >> height;
    } while (height < 0);
    vBMI = weight * 703 / (height * height);
    if(vBMI < 18.5){
        cout << "You are underweight.";
    } else if(vBMI > 18.5 && vBMI < 25){
        cout << "You have a optimal body.";
    }else if(vBMI > 25){
        cout << "You are overweight.";
    }
    return 0;
}

