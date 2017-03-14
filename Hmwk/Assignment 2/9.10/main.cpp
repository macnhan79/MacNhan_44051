/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 10, 2017, 6:00 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int *reverseArray(int *, int);
void showArray(int *, int);

int main(int argc, char** argv) {
    int arr[10] = {2, 4, 7, 2, 9, 6, 4, 7, 1, 8};
    int *reverseArr = reverseArray(arr, 10);
    showArray(reverseArr,10);
    delete reverseArr;
    return 0;
}

void showArray(int array[], int size) {
    for (int count = 0; count < size; count++)
        cout << *(array + count) << " ";
    cout << endl;
}

int *reverseArray(int array[], int size) {
    int *newArr = new int[size];
    for (int i = size - 1, j = 0; i >= 0; i--, j++) {
        *(newArr + j) = *(array + i);
    }
    return newArr;
}

