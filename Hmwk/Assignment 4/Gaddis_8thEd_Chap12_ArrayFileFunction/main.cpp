/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on April 2, 2017, 11:02 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
void arrayToFile(string, int *, int);
void fileToArray(string, int *, int);

/*
 * 
 */
int main(int argc, char** argv) {
    //create a array
    const int SIZE = 10;
    int array[SIZE] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0};
    string fileName = "ArrayFileFunction.dat";
    //write to file
    arrayToFile(fileName, array, SIZE);
    //read from file
    fileToArray(fileName, array, SIZE);

    //display array
    cout << "The array read from file: " << endl;
    for (int i = 0; i < SIZE; i++) {
        cout << setw(3) << array[i];
    }
    return 0;
}

void arrayToFile(string fileName, int *arr, int size) {
    //file
    fstream dataFileOut;
    cout << "Writing the data to the file" << endl;
    dataFileOut.open("ArrayFileFunction.dat", ios::out | ios::binary);
    dataFileOut.write(reinterpret_cast<char *>(arr), sizeof(arr));
    dataFileOut.close();
}

void fileToArray(string fileName, int *arr, int size) {
    fstream dataFileIn;
    dataFileIn.open("ArrayFileFunction.dat", ios::in | ios::binary);
    dataFileIn.read(reinterpret_cast<char *> (arr), sizeof (arr));
    dataFileIn.close();
}
