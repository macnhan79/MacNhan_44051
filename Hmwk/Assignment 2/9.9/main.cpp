/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 10, 2017, 4:19 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
float getMedian(int *, int);
void selectionSort(int *, int);

int main(int argc, char** argv) {
    int array1[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    selectionSort(array1, 9);
    cout << getMedian(array1, 9) << endl;


    int array[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    selectionSort(array, 8);
    cout << getMedian(array, 8);
    return 0;
}

float getMedian(int array[], int size) {
    if (size % 2 == 1) {
        return static_cast<float> (*(array + (size - 1) / 2));
    } else {
        return (static_cast<float> (*(array + (size - 2) / 2)) + *(array + size/2)) / 2;
    }
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

