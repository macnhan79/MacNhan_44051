/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 10, 2017, 6:49 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
float getMedian(int *, int);
void selectionSort(int *, int);
int getMode(int *, int);
float getMean(int *, int);

int main(int argc, char** argv) {
    int SIZE;
    do {
        cout << "Enter the number of array: ";
        cin >> SIZE;
    } while (SIZE < 0);
    int *arr = new int[SIZE];
    for (int i = 0; i < SIZE; i++) {
        cout << "Enter element " << i << ": ";
        cin >> *(arr + i);
    }
    selectionSort(arr, SIZE);
    cout << "Mode: " << getMode(arr, SIZE) << endl;
    cout << "Median: " << getMedian(arr, SIZE) << endl;
    cout << "Mean: " << getMean(arr, SIZE) << endl;
    return 0;
}

float getMean(int array[], int size) {
    float total;
    for (int i = 0; i < size; i++) {
        total += *(array + i);
    }
    return total / size;
}

float getMedian(int array[], int size) {
    if (size % 2 == 1) {
        return static_cast<float> (*(array + (size - 1) / 2));
    } else {
        return (static_cast<float> (*(array + (size - 2) / 2)) + *(array + size / 2)) / 2;
    }
}

int getMode(int array[], int size) {
    int countOld = 1, countNew = 0;
    int beginNum = *(array);
    for (int i = 1; i < size; i++) {
        if (beginNum == *(array + i)) {
            beginNum = *(array + i);
            countOld++;
        } else {
            beginNum = *(array + i);
            if (countOld > countNew) {
                countNew = countOld;
                countOld = 1;
            } else {

            }
        }
    }
    if (countNew == 1)
        return -1;
    else
        return countNew;
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
