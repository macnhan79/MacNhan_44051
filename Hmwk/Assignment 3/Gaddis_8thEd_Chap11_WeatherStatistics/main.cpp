/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 22, 2017, 8:22 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "WeatherData.h"

/*
 * 
 */
int main(int argc, char** argv) {
    int SIZE = 12;
    float totalRain = 0;
    float highestTemp = 0;
    int monthHighestTemp = 0;
    float lowestTemp = 0;
    int monthLowestTemp = 0;
    float averageTemp = 0;
    WeatherData *weather = new WeatherData[SIZE];
    for (int i = 0; i < SIZE; i++) {
        cout << "Month " << i + 1 << endl;
        //input total rain
        cout << "Enter total rainfall: ";
        cin >> weather[i].totalRainfall;
        //add total rain
        totalRain += weather[i].totalRainfall;
        //input high temp
        do {
            cout << "Enter high temperature: ";
            cin >> weather[i].highTemperature;
        } while (weather[i].highTemperature < -100 || weather[i].highTemperature > 140);
        //set the highest temperature
        if (weather[i].highTemperature > highestTemp) {
            highestTemp = weather[i].highTemperature;
            monthHighestTemp = i;
        }
        //input low temp
        do {
            cout << "Enter low temperature: ";
            cin >> weather[i].lowTemperature;
            if (i == 0) lowestTemp = weather[i].lowTemperature;
        } while ((weather[i].lowTemperature < -100 || weather[i].lowTemperature > 140) || weather[i].lowTemperature > weather[i].highTemperature);
        //set the lowest temperature
        if (weather[i].lowTemperature < lowestTemp) {
            lowestTemp = weather[i].lowTemperature;
            monthLowestTemp = i;
        }
        //set the average temp of the month
        weather[i].averageTemperature = (weather[i].highTemperature + weather[i].lowTemperature) / 2;
        //add average temp
        averageTemp += weather[i].averageTemperature;
    }
    cout << "-----------------------\n";
    cout << "Total rainfall for the year: " << totalRain << endl;
    cout << "The average monthly rainfall: " << totalRain / 12 << endl;
    cout << "The highest temperature in month " << monthHighestTemp << ": " << highestTemp << endl;
    cout << "The lowest temperature in month " << monthLowestTemp << ": " << lowestTemp << endl;
    cout << "The average temperature: " << averageTemp / 12 << endl;



    return 0;
}

