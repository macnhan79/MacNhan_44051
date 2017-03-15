/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 10, 2017, 3:41 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
int doSomething(int *, int *);

int main(int argc, char** argv) {
    int x = 2;
    int y = 3;
    cout << doSomething(&x, &y);
    return 0;
}

int doSomething(int *x, int *y) {
    int temp = *x;
    *x = *y * 10;
    *y = temp * 10;
    return *x + *y;
}

