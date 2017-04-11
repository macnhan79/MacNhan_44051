/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on April 2, 2017, 6:57 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;
bool cinValidNumber(int &);
void callMenu(char *);
void enterString(char *);
int countVowels(char *);
int countConsonants(char *);
/*
 * 
 */
const int LENGTH = 100;

int main(int argc, char** argv) {
    char word[LENGTH] = "Test string";
    enterString(word);
    callMenu(word);


    return 0;
}

void callMenu(char *c) {
    int choice = -1;
    do {
        do {
            cout << "1. Count the number of vowels in the string" << endl;
            cout << "2. Count the number of consonants in the string" << endl;
            cout << "3. Count both the vowels and consonants in the string" << endl;
            cout << "4. Enter another string" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
        } while (!cinValidNumber(choice));
    } while (choice < 1 || choice > 5);
    cout << "-------------------------------" << endl;
    switch (choice) {
        case 1:
            cout << "The number of vowels in the string: " << countVowels(c) << endl;
            cout << "Press [Enter] to continue...";
            cin.ignore();
            cin.get();
            callMenu(c);
            break;
        case 2:
            cout << "The number of consonants in the string: " << countConsonants(c) << endl;
            cout << "Press [Enter] to continue...";
            cin.ignore();
            cin.get();
            callMenu(c);
            break;
        case 3:
            cout << "The number of vowels in the string: " << countVowels(c) << endl;
            cout << "The number of consonants in the string: " << countConsonants(c) << endl;
            cout << "Press [Enter] to continue...";
            cin.ignore();
            cin.get();
            callMenu(c);
            break;
        case 4:
            enterString(c);
            cout << "Press [Enter] to continue...";
            cin.ignore();
            cin.get();
            callMenu(c);
            break;
        default:
            exit(0);
    }
}

void enterString(char *c) {
    cout << "Enter your string: ";
    cin.getline(c, LENGTH);
}

int countVowels(char *c) {
    int len = strlen(c);
    int vowels = 0;
    for (int i = 0; i < len; i++) {
        switch (tolower(c[i])) {
            case 'a':
            case 'e':
            case 'i':
            case 'u':
            case 'o':
                vowels++;
        }
    }
    return vowels;
}

int countConsonants(char *c) {
    int len = strlen(c);
    int consonants = 0;
    int vowels = countVowels(c);
    for (int i = 0; i < len; i++) {
        char a = tolower(c[i]);
        if (c[i] >= 'a' && c[i] <= 'z') {
            consonants++;
        }
    }
    return consonants - vowels;
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