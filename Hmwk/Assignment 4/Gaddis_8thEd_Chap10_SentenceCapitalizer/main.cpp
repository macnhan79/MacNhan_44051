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
int capitatlizer(char *);

/*
 * 
 */
int main(int argc, char** argv) {
    const int LENGTH = 100;
    char word[LENGTH];

    cout << "Enter your string: ";
    cin.getline(word, LENGTH);
    capitatlizer(word);
    cout << "The sentence after capitalize: " << word << endl;
    return 0;
}

void capitatlizer(char *c) {
    int len = strlen(c);
    if (len != 0) {
        c[0] = toupper(c[0]);
    }
    for (int i = 1; i < len; i++) {
        if (c[i] == ' ' && i != (len - 1)) {
            i++;
            c[i] = toupper(c[i]);
        }
    }
}