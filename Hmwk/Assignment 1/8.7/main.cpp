#include <iostream>
#include <string>
#include <stdlib.h>
#include <cstring>
using namespace std;

int binarySearch(const string array[], int numElems, string value) {
    int first = 0, // First array element
            last = numElems - 1, // Last array element
            middle, // Midpoint of search
            position = -1; // Position of search value
    bool found = false; // Flag

    while (!found && first <= last) {
        middle = (first + last) / 2; // Calculate midpoint
        if (array[middle] == value) // If value is found at mid
        {
            found = true;
            position = middle;
        }//array[middle] > value
        else if (strcmp(value.c_str(), array[middle].c_str())) // If value is in lower half
            last = middle - 1;
        else
            first = middle + 1; // If value is in upper half
    }
    return position;
}

void selectionSort(string array[], int size) {
    int startScan, minIndex;
    string minValue;
    for (startScan = 0; startScan < (size - 1); startScan++) {
        minIndex = startScan;
        minValue = array[startScan];
        for (int index = startScan + 1; index < size; index++) {
            if (strcmp(array[index].c_str(), minValue.c_str())) {
                minValue = array[index];
                minIndex = index;
            }
        }
        array[minIndex] = array[startScan];
        array[startScan] = minValue;
    }
}

int main() {
    const int NUM_NAMES = 20;
    string names[NUM_NAMES] = {"Collins, Bill", "Smith, Bart", "Allen, Jim",
        "Griffin, Jim", "Stamey, Marty", "Rose, Geri",
        "Taylor, Terri", "Johnson, Jill", "Allison, Jeff",
        "Looney, Joe", "Wolfe, Bill", "James, Jean",
        "Weaver, Jim", "Pore, Bob", "Rutherford, Greg",
        "Javens, Renee", "Harrison, Rose", "Setzer, Cathy",
        "Pike, Gordon", "Holland, Beth"};

    // Insert your code to complete this program
    selectionSort(names, 20);
    int found = binarySearch(names, 20, "Collins");
    if(found)
        cout << "Found." << endl;
    else
        cout << "Not Found." << endl;
    return 0;
}
