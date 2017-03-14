/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 10, 2017, 1:41 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
void selectionSort(int *, string *, int);
void showArray(int *, string *, int);

int main(int argc, char** argv) {
    int SIZE;
    do {
        cout << "How many student: ";
        cin >> SIZE;
    } while (SIZE < 0);

    string *name = new string[SIZE];
    int *score = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        do {
            cout << "Enter name: ";
            cin >> *(name + i);
            cout << "Enter score of" << *(name + i) << " : ";
            cin >> *(score + i);
        } while (*(score + i) < 0);
    }
    selectionSort(score, name, SIZE);
    cout << "List of student in ascending order:  " << endl;
    showArray(score, name, SIZE);
    delete score;
    delete name;
    return 0;
}

void showArray(int array[], string arrayName[], int size) {
    for (int count = 0; count < size; count++) {
        cout << *(arrayName + count) << ": ";
        cout << *(array + count) << " ";
    }
    cout << endl;
}

void selectionSort(int arrayScore[], string arrayName[], int size) {
    int startScan, minIndex, minValue;
    string tempName;
    for (startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minValue = *(arrayScore + startScan);
        tempName = *(arrayName + startScan);
        for (int index = startScan + 1; index < size; index++) {
            if (*(arrayScore + index) < minValue) {
                minValue = *(arrayScore + index);
                tempName = *(arrayName + index);
                minIndex = index;
            }
        }
        *(arrayName + minIndex) = *(arrayName + startScan);
        *(arrayScore + minIndex) = *(arrayScore + startScan);
        *(arrayScore + startScan) = minValue;
        *(arrayName + startScan) = tempName;
    }
}