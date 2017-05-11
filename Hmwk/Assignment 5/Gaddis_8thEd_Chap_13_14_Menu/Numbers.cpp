/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Numbers.h"

string Numbers::lessThan20[20] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};
string Numbers::tens[10] = {"", "ten", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};
string hundred = "hundred";
string thousand = "thousand";

Numbers::Numbers(unsigned int num){
    this->number = num;
}

void Numbers::SetNumber(int number) {
    this->number = number;
}

int Numbers::GetNumber() const {
    return number;
}

void Numbers::print(int num) {
    if (num >= 1000) {
        print(num / 1000);
        cout << " thousand";
        if (num % 1000) {
            if (num % 1000 < 100) {
                cout << " and";
            }
            cout << " ";
            print(num % 1000);
        }
    } else if (num >= 100) {
        print(num / 100);
        cout << " hundred";
        if (num % 100) {
            cout << " and ";
            print(num % 100);
        }
    } else if (num >= 20) {
        cout << tens[num / 10];
        if (num % 10) {
            cout << " ";
            print(num % 10);
        }
    } else {
        cout << lessThan20[num];
    }
}
