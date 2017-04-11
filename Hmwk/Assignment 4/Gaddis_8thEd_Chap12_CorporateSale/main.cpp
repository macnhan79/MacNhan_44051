/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on April 2, 2017, 11:48 PM
 */

#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>
using namespace std;
#include "SaleData.h"
bool cinValidNumber(float &);

/*
 * 
 */
int main(int argc, char** argv) {
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

   
    return 0;
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