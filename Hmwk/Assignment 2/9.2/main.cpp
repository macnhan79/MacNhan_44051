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
void selectionSort(int *, int);
float averageScore(int *, int);

void showArray(int *, int);

int main(int argc, char** argv) {
    int SIZE;
    do {
        cout << "How many test score: ";
        cin >> SIZE;
    } while (SIZE < 0);
    int *score = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        do {
            cout << "Enter score: ";
            cin >> *(score + i);
        } while (*(score + i) < 0);
    }
    selectionSort(score, SIZE);
    cout << "Average score: " << averageScore(score, SIZE) << endl;
    cout << "List of score in ascending order:  ";
    showArray(score, SIZE);
    delete score;
    return 0;
}

void showArray(int array[], int size) {
    for (int count = 0; count < size; count++)
        cout << *(array + count) << " ";
    cout << endl;
}

float averageScore(int array[], int SIZE) {
    float total = 0;
    for (int i = 0; i < SIZE; i++) {
        total += *(array + i);
    }
    return total / SIZE;
}

void selectionSort(int array[], int size) {
    int startScan, minIndex, minValue;

    for (startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minValue = *(array + startScan);
        for (int index = startScan + 1; index < size; index++) {
            if (*(array + index) < minValue) {
                minValue = *(array + index);
                minIndex = index;
            }
        }
        *(array + minIndex) = *(array + startScan);
        *(array + startScan) = minValue;
    }
}