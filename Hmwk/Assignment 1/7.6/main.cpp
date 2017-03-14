/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 5, 2017, 9:17 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    char table[3][30][1];
    ifstream inputFile;
    ofstream out;
    out.open("RainOrShine.txt");
    int rainJune = 0, rainJuly = 0, rainAug = 0, cJune = 0, cJuly = 0, cAug = 0, sJune = 0, sJuly = 0, sAug = 0;
    inputFile.open("data.txt");
    for (int m = 0; m < 3; m++) {
        for (int d = 0; d < 30; d++) {
            char value;
            inputFile >> value;
            table[m][d][0] = value;
            //count rain,cloud,sunny
            int a = cJune;
            if (m == 0) {
                switch (value) {
                    case 'R':
                        rainJune++;
                        break;
                    case 'C':
                        cJune++;
                        break;
                    case 'S':
                        sJune++;
                        break;
                }
            } else if (m == 1) {
                switch (value) {
                    case 'R':
                        rainJuly++;
                        break;
                    case 'C':
                        cJuly++;
                        break;
                    case 'S':
                        sJuly++;
                        break;
                }
            } else {
                switch (value) {
                    case 'R':
                        rainAug++;
                        break;
                    case 'C':
                        cAug++;
                        break;
                    case 'S':
                        sAug++;
                        break;
                }
            }
        }
    }
    string highestRain = "June";
    if (rainJune < rainJuly) {
        highestRain = "July";
        if (rainJuly < rainAug)
            highestRain = "August";
    }
    if (rainJune < rainAug) {
        highestRain = "August";
        if (rainJuly > rainAug)
            highestRain = "July";
    }
    out << "June" << endl;
    out << "The number of rainny days: " << rainJune << endl;
    out << "The number of cloudy days: " << cJune << endl;
    out << "The number of sunny days: " << sJune << endl;
    out << "July" << endl;
    out << "The number of rainny days: " << rainJuly << endl;
    out << "The number of cloudy days: " << cJuly << endl;
    out << "The number of sunny days: " << sJuly << endl;
    out << "August" << endl;
    out << "The number of rainny days: " << rainAug << endl;
    out << "The number of cloudy days: " << cAug << endl;
    out << "The number of sunny days: " << sAug << endl;
    out << "The month had the largest number of rainy days: " << highestRain << endl;
    return 0;
}

