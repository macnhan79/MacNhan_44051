/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on April 3, 2017, 12:49 AM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //file name
    string fileName;
    //string to search
    string search;
    //input file name
    cout << "Enter the file name: ";
    cin >> fileName;
    //input the string need to search
    cout << "Enter the string search: ";
    cin.ignore();
    getline(cin, search);


    //read data from file
    fstream in;
    in.open(fileName.c_str(), ios::in);
    string input;
    int counter;
    //get the first line
    getline(in, input);
    //loop until eof
    while (in) {
        //find the string need to search that exists???
        int found = input.find(search);
        if (found > 0) {
            cout << input << endl;
            counter++;
        }
        //get the next line
        getline(in, input);
    }
    //print the number of time string search appears in file
    cout << "The number of time of \"" << search << "\" appeared: " << counter << endl;
    return 0;
}

