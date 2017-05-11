/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on May 3, 2017, 12:12 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "RetailItem.h"
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    //init
    RetailItem r1("Jacket", 12, 59.95);
    RetailItem r2("Designer Jeans", 40, 34.95);
    RetailItem r3("Shirt", 20, 24.95);
    //print
    cout << "\tDescription\tUnits On Hand\tPrice" << endl;
    cout << "Item #1\t" << r1.GetDescription()
            << "\t\t" << r1.GetUnitsOnHand()
            << "\t\t" << r1.GetPrice() << endl;
    cout << "Item #2\t" << r2.GetDescription()
            << "\t" << r2.GetUnitsOnHand()
            << "\t\t" << r2.GetPrice() << endl;
    cout << "Item #3\t" << r3.GetDescription()
            << "\t\t" << r3.GetUnitsOnHand()
            << "\t\t" << r3.GetPrice() << endl;
    return 0;
}

