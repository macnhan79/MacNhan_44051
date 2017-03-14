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
int getMode(int *, int);
void selectionSort(int *, int);

int main(int argc, char** argv) {
    int array[20] = {1, 1, 2, 2, 2, 3, 3, 3, 3, 3, 3, 3, 4, 4, 4, 4, 4, 5, 5, 5};
    selectionSort(array, 20);
    cout << getMode(array, 20);
    return 0;
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

