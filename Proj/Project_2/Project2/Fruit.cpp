/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Fruit.h"
Fruit::Fruit() {
    setX((rand() % (60 - 0 + 1)) + 0); // 
    setY((rand() % (30 - 0 + 1)) + 0); // 
    setSymbol('@');
    setPoints(4);
}

void Fruit::reLocation() {
    setX((rand() % (60 - 0 + 1)) + 0); // 
    setY((rand() % (30 - 0 + 1)) + 0); // 
}

