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

enum Month {
    January, February, March, April, May, June, July, August, September, October, November, December
};

/*
 * 
 */
string displayMonth(Month);

int main(int argc, char** argv) {

    Month month;
    int SIZE = 12;
    float totalRain = 0;
    float highestTemp = 0;
    Month monthHighestTemp = January;
    float lowestTemp = 0;
    Month monthLowestTemp = January;
    float averageTemp = 0;
    WeatherData *weather = new WeatherData[SIZE];
    for (month = January; month <= December; month = static_cast<Month> (month + 1)) {
        cout << "Month " << displayMonth(month) << endl;
        //input total rain
        cout << "Enter total rainfall: ";
        cin >> weather[month].totalRainfall;
        //add total rain
        totalRain += weather[month].totalRainfall;
        //input high temp
        do {
            cout << "Enter high temperature: ";
            cin >> weather[month].highTemperature;
        } while (weather[month].highTemperature < -100 || weather[month].highTemperature > 140);
        //set the highest temperature
        if (weather[month].highTemperature > highestTemp) {
            highestTemp = weather[month].highTemperature;
            monthHighestTemp = month;
        }
        //input low temp
        do {
            cout << "Enter low temperature: ";
            cin >> weather[month].lowTemperature;
            if (month == 0) lowestTemp = weather[month].lowTemperature;
        } while ((weather[month].lowTemperature < -100 || weather[month].lowTemperature > 140) || weather[month].lowTemperature > weather[month].highTemperature);
        //set the lowest temperature
        if (weather[month].lowTemperature < lowestTemp) {
            lowestTemp = weather[month].lowTemperature;
            monthLowestTemp = month;
        }
        //set the average temp of the month
        weather[month].averageTemperature = (weather[month].highTemperature + weather[month].lowTemperature) / 2;
        //add average temp
        averageTemp += weather[month].averageTemperature;
    }
    cout << "-----------------------\n";
    cout << "Total rainfall for the year: " << totalRain << endl;
    cout << "The average monthly rainfall: " << totalRain / 12 << endl;
    cout << "The highest temperature is " << displayMonth(monthHighestTemp) << ": " << highestTemp << endl;
    cout << "The lowest temperature is " << displayMonth(monthLowestTemp) << ": " << lowestTemp << endl;
    cout << "The average temperature: " << averageTemp / 12 << endl;



    return 0;
}

string displayMonth(Month m) {
    string name;
    switch (m) {
        case January: name = "January";
            break;
        case February: name = "February";
            break;
        case March: name = "March";
            break;
        case April: name = "April";
            break;
        case May: name = "May";
            break;
        case June: name = "June";
            break;
        case July: name = "July";
            break;
        case August: name = "August";
            break;
        case September: name = "September";
            break;
        case October: name = "October";
            break;
        case November: name = "November";
            break;
        case December: name = "December";
    }
    return name;
}
