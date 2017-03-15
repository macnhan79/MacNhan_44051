/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: rcc
 *
 * Created on March 14, 2017, 1:56 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
void problem1();
void selectionSort(int *, int);
float averageScore(int *, int);
void showArray(int *, int);

void problem2();
int* remove(int *, int);

void problem3();
void selectionSort(int *, string *, int);
void showArray(int *, string *, int);

void problem4();
int *reverseArray(int *, int);

void problem5();
int doSomething(int *, int *);

void problem6();
void arrSelectSort(int *[], int);
void showArrPtr(int *[], int);


void problem7();
void arrSelectSort1(int *[], int);
void showArrPtr(int *[], int);

void problem8();
float getMedian(int *, int);
int getFre(int *, int, int &);
float getMean(int *, int);

int main(int argc, char** argv) {
    int menu;

    do {
        do {
            cout << "1.  Type 1  for Test scores 1\n";
            cout << "2.  Type 2  for Test scores 2\n";
            cout << "3.  Type 3  for Test scores 3\n";
            cout << "4.  Type 4  for Reverse an array\n";
            cout << "5.  Type 5  for Pointer Rewrite\n";
            cout << "6.  Type 6  for Donation 1\n";
            cout << "7.  Type 7  for Donation 2\n";
            cout << "8.  Type 8  for Mean, Median, Mode\n";
            cout << "Enter problem you want: ";
            cin>>menu;
        } while (menu < 1 || menu > 10);

        switch (menu) {
            case 1: problem1();
                break;
            case 2: problem2();
                break;
            case 3: problem3();
                break;
            case 4: problem4();
                break;
            case 5: problem5();
                break;
            case 6: problem6();
                break;
            case 7: problem7();
                break;
            case 8: problem8();
                break;

        }
    } while (menu > 0 && menu <= 10);
    return 0;

}

void problem1() {
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
}

void problem2() {
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
    int *score1 = remove(score, SIZE);
    cout << "List of score in ascending order:  ";
    showArray(score1, SIZE - 1);
    delete score1;
}

void problem3() {
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
            cout << "Enter score of " << *(name + i) << " : ";
            cin >> *(score + i);
        } while (*(score + i) < 0);
    }
    selectionSort(score, name, SIZE);
    cout << "List of student in ascending order:  " << endl;
    showArray(score, name, SIZE);
    delete score;
}

void problem4() {
    int arr[10] = {2, 4, 7, 2, 9, 6, 4, 7, 1, 8};
    int *reverseArr = reverseArray(arr, 10);
    cout << "The original array: ";
    showArray(arr,10);
    cout << "The reverse array: ";
    showArray(reverseArr, 10);
    delete reverseArr;
}

void problem5() {
    int x = 2;
    int y = 3;
    cout << "Return: "doSomething(&x, &y) << endl;
}

void problem6() {
    int NUM_DONATIONS = 15; // Number of donations
    do {
        cout << "Enter the number of donation: ";
        cin >> NUM_DONATIONS;
    } while (NUM_DONATIONS < 0);

    int *donations = new int[NUM_DONATIONS];
    //input donation
    for (int i = 0; i < NUM_DONATIONS; i++) {
        cout << "Enter donation " << i + 1 << ": ";
        cin >> *(donations + i);
    }

    int *arrPtr[NUM_DONATIONS];

    // Each element of arrPtr is a pointer to int. Make each
    // element point to an element in the donations array.
    for (int count = 0; count < NUM_DONATIONS; count++)
        arrPtr[count] = &donations[count];

    // Sort the elements of the array of pointers.
    arrSelectSort(arrPtr, NUM_DONATIONS);

    // Display the donations using the array of pointers. This
    // will display them in sorted order.
    cout << "The donations, sorted in ascending order are: \n";
    showArrPtr(arrPtr, NUM_DONATIONS);

    // Display the donations in their original order.
    cout << "The donations, in their original order are: \n";
    showArray(donations, NUM_DONATIONS);
    delete donations;
}

void problem7() {
    int NUM_DONATIONS = 15; // Number of donations
    do {
        cout << "Enter the number of donation: ";
        cin >> NUM_DONATIONS;
    } while (NUM_DONATIONS < 0);

    int *donations = new int[NUM_DONATIONS];
    //input donation
    for (int i = 0; i < NUM_DONATIONS; i++) {
        cout << "Enter donation " << i + 1 << ": ";
        cin >> *(donations + i);
    }

    int *arrPtr[NUM_DONATIONS];

    // Each element of arrPtr is a pointer to int. Make each
    // element point to an element in the donations array.
    for (int count = 0; count < NUM_DONATIONS; count++)
        arrPtr[count] = &donations[count];

    // Sort the elements of the array of pointers.
    arrSelectSort1(arrPtr, NUM_DONATIONS);

    // Display the donations using the array of pointers. This
    // will display them in sorted order.
    cout << "The donations, sorted in descending order are: \n";
    showArrPtr(arrPtr, NUM_DONATIONS);

    // Display the donations in their original order.
    cout << "The donations, in their original order are: \n";
    showArray(donations, NUM_DONATIONS);
    delete donations;
}

void problem8() {
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
    int modeNumber;
    int freq = getFre(arr, SIZE, modeNumber);


    cout << "Mode number: " << modeNumber << endl;
    cout << "Frequency: " << freq << endl;
    cout << "Median: " << getMedian(arr, SIZE) << endl;
    cout << "Mean: " << getMean(arr, SIZE) << endl;
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

int* remove(int array[], int size) {
    int *arr = new int[size - 1];
    for (int i = 0; i < size - 1; i++) {
        *(arr + i) = *(array + i + 1);
    }
    delete array;
    return arr;
}

void showArray(int array[], string arrayName[], int size) {
    for (int count = 0; count < size; count++) {
        cout << *(arrayName + count) << ": ";
        cout << *(array + count) << " , ";
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

int *reverseArray(int array[], int size) {
    int *newArr = new int[size];
    for (int i = size - 1, j = 0; i >= 0; i--, j++) {
        *(newArr + j) = *(array + i);
    }
    return newArr;
}

int doSomething(int *x, int *y) {
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}

void arrSelectSort(int *arr[], int size) {
    int startScan, minIndex;
    int *minElem;

    for (startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minElem = arr[startScan];
        for (int index = startScan + 1; index < size; index++) {
            if (*(arr[index]) < *minElem) {
                minElem = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
}

void showArrPtr(int *arr[], int size) {
    for (int count = 0; count < size; count++)
        cout << *(arr[count]) << " ";
    cout << endl;
}

void arrSelectSort1(int *arr[], int size) {
    int startScan, minIndex;
    int *minElem;

    for (startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minElem = arr[startScan];
        for (int index = startScan + 1; index < size; index++) {
            if (*(arr[index]) > *minElem) {
                minElem = arr[index];
                minIndex = index;
            }
        }
        arr[minIndex] = arr[startScan];
        arr[startScan] = minElem;
    }
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

int getFre(int array[], int size, int &modenumber) {
    int countOld = 1, countNew = 0;
    int beginNum = *(array);
    for (int i = 1; i < size; i++) {
        if (beginNum == *(array + i)) {
            beginNum = *(array + i);
            countOld++;
        } else {
            beginNum = *(array + i);
            if (countOld > countNew) {
                modenumber = *(array + i - 1);
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
