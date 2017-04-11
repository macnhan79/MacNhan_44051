/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on April 3, 2017, 1:02 AM
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
    //file to to input
    string nameIn = "string.txt";
    //file name to output
    string nameOut = "test_encryption.txt";
    //file
    fstream in;
    fstream out;
    //open file
    in.open(nameIn.c_str(), ios::in);
    out.open(nameOut.c_str(), ios::out);
    //if file exists
    if (in) {
        string ch;
        //get the first line
        getline(in, ch);
        //loop to each character and add 10 to ASCII code
        for (int i = 0; i < ch.length(); i++) {
            ch[i] = ch[i] + 10;
        }
        //write to file
        out << ch;
        //loop to eof
        while (in) {
            //get the next line of file
            getline(in, ch);
            //loop to each character and add 10 to ASCII code
            for (int i = 0; i < ch.length(); i++) {
                ch[i] = ch[i] + 10;
            }
            //write to file
            out << ch;
        }
        //close to done what we write
        in.close();
        out.close();
    }
   
    return 0;
}

