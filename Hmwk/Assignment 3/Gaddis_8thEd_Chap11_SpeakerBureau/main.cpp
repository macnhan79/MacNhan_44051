/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 26, 2017, 2:55 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;
#include "Speaker.h"
/*
 * 
 */
bool cinValidNumber(float &);
bool cinValidNumber(int &);
void inputData(Speaker *);
void displayData(Speaker *);
void changeData(Speaker *);
void inputAnSpeaker(Speaker &);
void callMenu(Speaker *);

const int SIZE = 10;

int main(int argc, char** argv) {
    Speaker *s = new Speaker[SIZE];
    for (int i = 0; i < 10; i++) {
        s[i].fee = 0.0f + i;
        s[i].telephone = "test";
        s[i].speakingTopic = "test";
        s[i].name = "test";
    }
    callMenu(s);
    return 0;
}

void callMenu(Speaker *s) {
    int choice = -1;
    do {
        do {
            cout << "1. Enter data into the array." << endl;
            cout << "2. Change the content." << endl;
            cout << "3. Display all the data." << endl;
            cout << "Enter your choice: ";
        } while (!cinValidNumber(choice));
    } while (choice < 1 || choice > 3);
    cout << "-------------------------------" << endl;
    switch (choice) {
        case 1: inputData(s);
            break;
        case 2: changeData(s);
            break;
        case 3: displayData(s);
            break;
    }
}

void inputData(Speaker *s) {
    for (int i = 0; i < SIZE; i++) {
        cout << "Speaker " << i + 1 << endl;
        inputAnSpeaker(s[i]);
    }
    callMenu(s);
}

void displayData(Speaker *s) {
    for (int i = 0; i < SIZE; i++) {
        cout << "Name of speaker: " << s[i].name << endl;
        cout << "Telephone of speaker: " << s[i].telephone << endl;
        cout << "Topic of speaker: " << s[i].speakingTopic << endl;
        cout << "Free required: " << s[i].fee << endl;
        cout << "---------------------------------------" << endl;
    }
    callMenu(s);
}

void changeData(Speaker *s) {
    int index;
    do {
        do {
            cout << "Enter index (0 to 11): ";
        } while (!cinValidNumber(index));
    } while (index < 0 || index > 11);
    inputAnSpeaker(s[index]);
    callMenu(s);
}

void inputAnSpeaker(Speaker &s) {

    cout << "Enter name of speaker: ";
    cin.ignore();
    getline(cin, s.name);


    cout << "Enter telephone of speaker: ";
    getline(cin, s.telephone);

    cout << "Enter topic of speaker: ";
    getline(cin, s.speakingTopic);

    do {
        do {
            cout << "Enter fee required: ";
        } while (!cinValidNumber(s.fee));
    } while (s.fee < 0);
}

bool cinValidNumber(float &number) {
    cin >> number;
    bool isCorrect = true;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(80, '\n');
        isCorrect = false;
    }
    return isCorrect;
}
bool cinValidNumber(int &number) {
    float temp;
    cin >> temp;
    number = static_cast<int> (temp);
    bool isCorrect = true;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(80, '\n');
        isCorrect = false;
    }
    return isCorrect;
}