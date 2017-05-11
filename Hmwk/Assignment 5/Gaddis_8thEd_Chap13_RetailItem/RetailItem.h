/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   RetailItem.h
 * Author: admin
 *
 * Created on May 3, 2017, 1:05 AM
 */

#ifndef RETAILITEM_H
#define RETAILITEM_H
#include <string>
using namespace std;

class RetailItem {
private:
    string description;
    int unitsOnHand;
    double price;
public:
    RetailItem(string, int, double);

    void SetPrice(double);

    double GetPrice() const;

    void SetUnitsOnHand(int);

    int GetUnitsOnHand() const;

    void SetDescription(string);

    string GetDescription() const;
};

#endif /* RETAILITEM_H */

