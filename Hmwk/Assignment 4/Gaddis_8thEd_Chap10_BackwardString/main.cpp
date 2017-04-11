/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on April 2, 2017, 5:24 PM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
using namespace std;
void backwardString(char*);

/*
 * 
 */
int main(int argc, char** argv) {
    const int LENGTH = 100;
    char word[LENGTH];

    cout << "Enter your string: ";
    cin.getline(word, LENGTH);
    backwardString(word);
    return 0;
}

void backwardString(char * str) {
    int len = strlen(str);
    for (int i = 0; i < len/2; i++) {
        swap(str[i], str[len - i - 1]);
    }
    cout << "Your backward string: " << str << endl;
}
