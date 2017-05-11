/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include "Car.h"

Car::Car(int yearModel, string make) {
    this->yearModel = yearModel;
    this->make = make;
    this->speed = 0;
}

void Car::accelerate() {
    this->speed += 5;
}

void Car::brake() {
    this->speed -= 5;
}

void Car::SetSpeed(int speed) {
    this->speed = speed;
}

int Car::GetSpeed() const {
    return speed;
}

void Car::SetMake(string make) {
    this->make = make;
}

string Car::GetMake() const {
    return make;
}

void Car::SetYearModel(int yearModel) {
    this->yearModel = yearModel;
}

int Car::GetYearModel() const {
    return yearModel;
}

