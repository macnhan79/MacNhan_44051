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

/*
 * 
 */
int main(int argc, char** argv) {
    const int LENGTH = 100;
    char word[LENGTH];
    //input word
    cout << "Enter your string: ";
    cin.getline(word, LENGTH);
    //call wordCounter and display result
    cout << "The number of words: " << wordCounter(word) << endl;
    return 0;
}

int wordCounter(char *c) {
    int counter = 1;
    //if string has no character return 0
    if (strlen(c) == 0)
        return 0;
    //loop until end of char array
    while (*c != '\0') {
        //if current position is a space
        if (*c == ' ')
            //increase counter word
            counter++;
        //move position to next
        c++;
    }
    return counter;
}