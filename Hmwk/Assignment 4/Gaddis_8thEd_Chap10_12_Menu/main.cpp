/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on April 3, 2017, 1:44 AM
 */

#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;
#include "SaleData.h"

void problem1();
int wordCounter(char *);
int averageLetters(char *);

void problem2();
void backwardString(char*);

void problem3();
void capitatlizer(char *);

void problem4();
bool cinValidNumber(int &);
void callMenu(char *);
void enterString(char *);
int countVowels(char *);
int countConsonants(char *);
const int LENGTH = 100;

void problem5();
int wordCounter(char *);

void problem6();
void arrayToFile(string, int *, int);
void fileToArray(string, int *, int);

void problem7();
bool cinValidNumber(float &);

void problem8();
void problem9();
void problem10();

void callMenuMain();

/*
 * 
 */
int main(int argc, char** argv) {
    callMenuMain();
    return 0;
}

void problem1() {
    char word[LENGTH];
    cin.ignore();
    cout << "Enter your string: ";
    cin.getline(word, LENGTH);
    cout << "The average number of letters: " << averageLetters(word) << endl;
}

int averageLetters(char *c) {
    //count how many of word
    int len = wordCounter(c);
    //create a array with length = word
    int numOfWord[len];
    int counterWord = 0;
    int countLetter = 0;
    int i = 0;
    //loop until end of array
    while (c[i] != '\0') {
        //is space
        if (c[i] != ' ') {
            //count letter
            countLetter++;
        } else {
            //add the number of letter to array
            numOfWord[counterWord] = countLetter;
            //cout << numOfWord[counterWord] << endl;
            //increase the index
            counterWord++;
            countLetter = 0;
        }
        if (len == 1)
            numOfWord[0] = countLetter;
        i++;
    }
    //add the number of letter of the last word to array
    numOfWord[len - 1] = countLetter;
    int total = 0;
    //count total
    for (int i = 0; i < len; i++) {
        //cout << numOfWord[i] << endl;
        total += numOfWord[i];
    }
    int average = total / len;
    return average;
}

void problem2() {
    const int LENGTH = 100;
    char word[LENGTH];
//input string
    cout << "Enter your string: ";
    cin.getline(word, LENGTH);
    backwardString(word);
}

void backwardString(char * str) {
    int len = strlen(str);
    //loop to middle of string
    for (int i = 0; i < len / 2; i++) {
        //exchange the character
        swap(str[i], str[len - i - 1]);
    }
    cout << "Your backward string: " << str << endl;
}

void problem3() {
    char word[LENGTH];
    cin.ignore();
    //input string
    cout << "Enter your string: ";
    cin.getline(word, LENGTH);
    capitatlizer(word);
    cout << "The sentence after capitalize: " << word << endl;
}

void capitatlizer(char *c) {
    int len = strlen(c);
    //cap the first char
    if (len != 0) {
        c[0] = toupper(c[0]);
    }
    //loop to find a space and the position is not longer than length
    for (int i = 1; i < len; i++) {
        if (c[i] == ' ' && i != (len - 1)) {
            i++;
            c[i] = toupper(c[i]);
        }
    }
}

void problem4() {
    char word[LENGTH] = "Test string";
    enterString(word);
    callMenu(word);
}

void callMenu(char *c) {
    int choice = -1;
    do {
        do {
            cout << "1. Count the number of vowels in the string" << endl;
            cout << "2. Count the number of consonants in the string" << endl;
            cout << "3. Count both the vowels and consonants in the string" << endl;
            cout << "4. Enter another string" << endl;
            cout << "5. Exit" << endl;
            cout << "Enter your choice: ";
        } while (!cinValidNumber(choice));
    } while (choice < 1 || choice > 5);
    cout << "-------------------------------" << endl;
    switch (choice) {
        case 1:
            cout << "The number of vowels in the string: " << countVowels(c) << endl;
            cout << "Press [Enter] to continue...";
            cin.ignore();
            cin.get();
            callMenu(c);
            break;
        case 2:
            cout << "The number of consonants in the string: " << countConsonants(c) << endl;
            cout << "Press [Enter] to continue...";
            cin.ignore();
            cin.get();
            callMenu(c);
            break;
        case 3:
            cout << "The number of vowels in the string: " << countVowels(c) << endl;
            cout << "The number of consonants in the string: " << countConsonants(c) << endl;
            cout << "Press [Enter] to continue...";
            cin.ignore();
            cin.get();
            callMenu(c);
            break;
        case 4:
            enterString(c);
            cout << "Press [Enter] to continue...";
            cin.ignore();
            cin.get();
            callMenu(c);
            break;
        default:
            callMenuMain();
    }
}

void enterString(char *c) {
    cin.ignore();
    cout << "Enter your string: ";
    cin.getline(c, LENGTH);
}

int countVowels(char *c) {
    int len = strlen(c);
    int vowels = 0;
    //loop to the end of string to find vowels and increase counter
    for (int i = 0; i < len; i++) {
        switch (tolower(c[i])) {
            case 'a':
            case 'e':
            case 'i':
            case 'u':
            case 'o':
                vowels++;
        }
    }
    return vowels;
}

int countConsonants(char *c) {
    int len = strlen(c);
    int consonants = 0;
    //count vowels
    int vowels = countVowels(c);
    //loop to the end of string and count the alphabet
    for (int i = 0; i < len; i++) {
        char a = tolower(c[i]);
        if (c[i] >= 'a' && c[i] <= 'z') {
            consonants++;
        }
    }
    //return consonants = total of character from a->z - vowels
    return consonants - vowels;
}

bool cinValidNumber(int &number) {
    float temp;
    cin >> temp;
    number = static_cast<int> (temp);
    bool isCorrect = true;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(80, '\n');
        isCorrect = false;
    }
    return isCorrect;
}

void problem5() {
    char word[LENGTH];
    //input word
    cout << "Enter your string: ";
    cin.getline(word, LENGTH);
    //call wordCounter and display result
    cout << "The number of words: " << wordCounter(word) << endl;
}

int wordCounter(char *c) {
    int counter = 1;
    //if string has no character return 0
    if (strlen(c) == 0)
        return 0;
    //loop until end of char array
    while (*c != '\0') {
        //if current position is a space
        if (*c == ' ')
            //increase counter word
            counter++;
        //move position to next
        c++;
    }
    return counter;
}

void problem6() {
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
    cout << endl;
}

void arrayToFile(string fileName, int *arr, int size) {
    //file
    fstream dataFileOut;
    cout << "Writing the data to the file" << endl; //print what computer doing
    dataFileOut.open("ArrayFileFunction.dat", ios::out | ios::binary); //open file
    dataFileOut.write(reinterpret_cast<char *> (arr), sizeof (arr)); //write the array to file
    dataFileOut.close(); //close
}

void fileToArray(string fileName, int *arr, int size) {
    fstream dataFileIn;
    //open file
    dataFileIn.open("ArrayFileFunction.dat", ios::in | ios::binary);
    //read the array from file to arr menory
    dataFileIn.read(reinterpret_cast<char *> (arr), sizeof (arr));
    dataFileIn.close(); //close
}

void problem7() {
    //create a saledata array
    SaleData *sale = new SaleData[16];
    //loop to input saledata
    for (int i = 0; i < 16; i++) {
        int mod = i % 4;
        switch (mod) {
            case 0:
                sale[i].DivisionName = "East";
                sale[i].quarter = mod + 1;
                //check valid data sale and it shout be greater than 0
                do {
                    cout << "Enter " << sale[i].DivisionName << "'s of quarter " << sale[i].quarter << " sale: ";
                } while (!cinValidNumber(sale[i].quarterSales) && sale[i].quarterSales < 0);
                break;
            case 1:
                sale[i].DivisionName = "West";
                sale[i].quarter = mod + 1;
                //check valid data sale and it shout be greater than 0
                do {
                    cout << "Enter " << sale[i].DivisionName << "'s of quarter " << sale[i].quarter << " sale: ";
                } while (!cinValidNumber(sale[i].quarterSales) && sale[i].quarterSales < 0);
                break;
            case 2:
                sale[i].DivisionName = "North";
                sale[i].quarter = mod + 1;
                //check valid data sale and it shout be greater than 0
                do {
                    cout << "Enter " << sale[i].DivisionName << "'s of quarter " << sale[i].quarter << " sale: ";
                } while (!cinValidNumber(sale[i].quarterSales) && sale[i].quarterSales < 0);
                break;
            case 3:
                sale[i].DivisionName = "South";
                sale[i].quarter = mod + 1;
                //check valid data sale and it shout be greater than 0
                do {
                    cout << "Enter " << sale[i].DivisionName << "'s of quarter " << sale[i].quarter << " sale: ";
                } while (!cinValidNumber(sale[i].quarterSales) && sale[i].quarterSales < 0);
                break;
        }
    }
    //loop to display
    for (int i = 0; i < 16; i++) {
        cout << "Division name: " << sale[i].DivisionName << endl;
        cout << "Quarter: " << sale[i].quarter << endl;
        cout << "Quarterly sale: " << sale[i].quarterSales << endl;
    }
    //create file stream to ouput
    fstream out;
    out.open("corSale.dat", ios::out | ios::binary);
    //loop each saledata
    for (int i = 0; i < 16; i++) {
        //write to file
        out.write(reinterpret_cast<char *> (&sale[i]), sizeof (sale[i]));
    }
    out.close();


    //    fstream im;
    //    im.open("corSale.dat", ios::in | ios::binary);
    //    SaleData s;
    //    im.read(reinterpret_cast<char *> (&s), sizeof (s));
    //    while (im.eof()) {
    //        cout << "Division name: " << s.DivisionName << endl;
    //        cout << "Quarter: " << s.quarter << endl;
    //        cout << "Quarterly sale: " << s.quarterSales << endl;
    //        im.read(reinterpret_cast<char *> (&s), sizeof (s));
    //    }
    //    im.close();


}

bool cinValidNumber(float &number) {
    cin >> number;
    bool isCorrect = true;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(80, '\n');
        isCorrect = false;
    }
    return isCorrect;
}

void problem8() {
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
        cout << "Writing to file successful!" << endl;
    }
}

void problem9() {
    //file name in and out
    string nameIn;
    string nameOut;
    //file
    fstream dataFileIn;
    fstream dataFileOut;
    //input file name
    cout << "File name input: ";
    cin >> nameIn;
    cout << "File name output:";
    cin >>nameOut;
    //open file
    dataFileIn.open(nameIn.c_str(), ios::in);
    dataFileOut.open(nameOut.c_str(), ios::out);
    //read data
    string input;
    //get the first line
    getline(dataFileIn, input);
    //loop to eof
    while (dataFileIn) {
        string temp;
        //cap first character
        input[0] = toupper(input[0]);
        //loop to the end of string temp
        for (int i = 1; i < input.length(); i++) {
            //current character is "." and character in position i + 1 < length -1
            if (input[i] == '.' && (i + 1) < (input.length() - 1)) {
                //character in position i+1 is not " " and character in position i + 2 < length -1
                if (input[i + 1] != ' ' && (i + 2) < (input.length() - 1)) {
                    //upper character at position i + 1
                    input[i + 1] = toupper(input[i + 1]);
                    //move index to left + 2
                    i = i + 2;
                } else {
                    input[i + 2] = toupper(input[i + 2]);
                    i = i + 2;
                }
            } else {
                //upper character at position i
                input[i] = tolower(input[i]);
            }
        }
        //write to file
        dataFileOut << input;
        //get the next line
        getline(dataFileIn, input);
    }
    //close file
    dataFileOut.close();
    dataFileIn.close();
}

void problem10() {
    //file name
    string fileName;
    //string to search
    string search;
    //input file name
    cout << "Enter the file name: ";
    cin >> fileName;
    //input the string need to search
    cout << "Enter the string search: ";
    cin.ignore();
    getline(cin, search);


    //read data from file
    fstream in;
    in.open(fileName.c_str(), ios::in);
    string input;
    int counter;
    //get the first line
    getline(in, input);
    //loop until eof
    while (in) {
        //find the string need to search that exists???
        int found = input.find(search);
        if (found > 0) {
            cout << input << endl;
            counter++;
        }
        //get the next line
        getline(in, input);
    }
    //print the number of time string search appears in file
    cout << "The number of time of \"" << search << "\" appeared: " << counter << endl;
}

void callMenuMain() {
    int menu;
    do {
        do {
            cout << "1.  Type 1  for Average Letters\n";
            cout << "2.  Type 2  for Backward String\n";
            cout << "3.  Type 3  for Sentence Capitalizer\n";
            cout << "4.  Type 4  for Vowels and consonants\n";
            cout << "5.  Type 5  for Word counter\n";
            cout << "6.  Type 6  for Array File Function\n";
            cout << "7.  Type 7  for Corporate Sale\n";
            cout << "8.  Type 8  for Encryption File\n";
            cout << "9.  Type 9  for Sentence Filter\n";
            cout << "10.  Type 10  for String search\n";
            cout << "Enter problem you want: ";
            cin >> menu;
        } while (menu < 1 || menu > 10);

        switch (menu) {
            case 1:
                problem1();
                cout << "Press [Enter] to continue...";
                cin.ignore();
                cin.get();
                callMenuMain();
                break;
            case 2:
                cin.ignore();
                problem2();
                cout << "Press [Enter] to continue...";
                cin.ignore();
                cin.get();
                callMenuMain();
                break;
            case 3: problem3();
                cout << "Press [Enter] to continue...";
                cin.ignore();
                cin.get();
                callMenuMain();
                break;
            case 4: problem4();
                cout << "Press [Enter] to continue...\n";
                cin.ignore();
                cin.get();
                callMenuMain();
                break;
            case 5: problem5();
                cout << "Press [Enter] to continue...\n";
                cin.ignore();
                cin.get();
                callMenuMain();
                break;
            case 6: problem6();
                cout << "Press [Enter] to continue...\n";
                cin.ignore();
                cin.get();
                callMenuMain();
                break;
            case 7: problem7();
                cout << "Press [Enter] to continue...\n";
                cin.ignore();
                cin.get();
                callMenuMain();
                break;
            case 8: problem8();
                cout << "Press [Enter] to continue...\n";
                cin.ignore();
                cin.get();
                callMenuMain();
                break;
            case 9: problem9();
                cout << "Press [Enter] to continue...\n";
                cin.ignore();
                cin.get();
                callMenuMain();
                break;
            case 10: problem10();
                cout << "Press [Enter] to continue...\n";
                cin.ignore();
                cin.get();
                callMenuMain();
                break;

        }
    } while (menu > 0 && menu <= 10);
}