/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on April 2, 2017, 5:47 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
int wordCounter(char *);
int averageLetters(char *);

/*
 * 
 */
int main(int argc, char** argv) {
    const int LENGTH = 100;
    char word[LENGTH];

    cout << "Enter your string: ";
    cin.getline(word, LENGTH);

    cout << "The average number of letters: " << averageLetters(word) << endl;
    return 0;
}

int wordCounter(char *c) {
    int counter = 1;
    if (strlen(c) == 0)
        return 0;
    while (*c != '\0') {
        if (*c == ' ')
            counter++;
        c++;
    }
    return counter;
}

int averageLetters(char *c) {
    int len = wordCounter(c);
    int numOfWord[len];
    int counterWord = 0;
    int countLetter = 0;
    int i = 0;
    while (c[i] != '\0') {
        if (c[i] != ' ') {
            countLetter++;
        } else {

            numOfWord[counterWord] = countLetter;
            //cout << numOfWord[counterWord] << endl;
            counterWord++;
            countLetter = 0;
        }
        if (len == 1)
            numOfWord[0] = countLetter;
        i++;
    }
    numOfWord[len - 1] = countLetter;
    int total = 0;
    for (int i = 0; i < len; i++) {
        cout << numOfWord[i] << endl;
        total += numOfWord[i];
    }
    int average = total / len;
    return average;
}