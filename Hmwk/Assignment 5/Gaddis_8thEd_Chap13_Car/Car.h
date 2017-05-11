/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Car.h
 * Author: admin
 *
 * Created on May 3, 2017, 12:45 AM
 */

#ifndef CAR_H
#define CAR_H
#include <string>
using namespace std;

class Car {
private:
    int yearModel;
    string make;
    int speed;
public:
    Car(int, string);
    void SetSpeed(int);

    int GetSpeed() const;

    void SetMake(string);

    string GetMake() const;

    void SetYearModel(int);

    int GetYearModel() const;

    void accelerate();
    void brake();
};


#endif /* CAR_H */

