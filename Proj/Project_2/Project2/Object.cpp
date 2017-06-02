/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Object.h"

Object::Object() {
    symbol = ' ';
    points = 0;
}

void Object::operator=(const Object& obj) {
    this->points = this->points + obj.points;
    x = obj.x;
    y = obj.y;
    symbol = obj.symbol;
}

void Object::setPoints(int points) {
    this->points = points;
}

int Object::getPoints() const {
    return points;
}

void Object::setY(int y) {
    this->y = y;
}

int Object::getY() const {
    return y;
}

void Object::setX(int x) {
    this->x = x;
}

int Object::getX() const {
    return x;
}

char Object::getSymbol()const {
    return symbol;
}

void Object::setSymbol(char symbol) {
    this->symbol = symbol;
}