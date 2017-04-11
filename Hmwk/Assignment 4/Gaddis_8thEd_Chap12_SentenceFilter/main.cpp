/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on April 2, 2017, 9:30 PM
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
    //file name in and out
    string nameIn;
    string nameOut;
    //file
    fstream dataFileIn;
    fstream dataFileOut;
    //input file name
    cout << "File name input: ";
    cin >> nameIn;
    cout << "File name output:";
    cin >>nameOut;
    //open file
    dataFileIn.open(nameIn.c_str(), ios::in);
    dataFileOut.open(nameOut.c_str(), ios::out);
    //read data
    string input;
    //get the first line
    getline(dataFileIn, input);
    //loop to eof
    while (dataFileIn) {
        string temp;
        //cap first character
        input[0] = toupper(input[0]);
        //loop to the end of string temp
        for (int i = 1; i < input.length(); i++) {
            //current character is "." and character in position i + 1 < length -1
            if (input[i] == '.' && (i + 1) < (input.length() - 1)) {
                //character in position i+1 is not " " and character in position i + 2 < length -1
                if (input[i + 1] != ' ' && (i + 2) < (input.length() - 1)) {
                    //upper character at position i + 1
                    input[i + 1] = toupper(input[i + 1]);
                    //move index to left + 2
                    i = i + 2;
                } else {
                    input[i + 2] = toupper(input[i + 2]);
                    i = i + 2;
                }
            } else {
                //upper character at position i
                input[i] = tolower(input[i]);
            }
        }
        //write to file
        dataFileOut << input;
        //get the next line
        getline(dataFileIn, input);
    }
    //close file
    dataFileOut.close();
    dataFileIn.close();


    return 0;
}

