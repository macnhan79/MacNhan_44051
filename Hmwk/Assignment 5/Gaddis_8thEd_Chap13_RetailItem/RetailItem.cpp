/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "RetailItem.h"

RetailItem::RetailItem(string desc, int unitsOnHand, double price) {
    this->description = desc;
    this->unitsOnHand = unitsOnHand;
    this->price = price;
}

void RetailItem::SetPrice(double price) {
    this->price = price;
}

double RetailItem::GetPrice() const {
    return price;
}

void RetailItem::SetUnitsOnHand(int unitsOnHand) {
    this->unitsOnHand = unitsOnHand;
}

int RetailItem::GetUnitsOnHand() const {
    return unitsOnHand;
}

void RetailItem::SetDescription(string description) {
    this->description = description;
}

string RetailItem::GetDescription() const {
    return description;
}