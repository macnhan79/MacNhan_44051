/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on March 5, 2017, 8:58 PM
 */

#include <cstdlib>
#include <iostream>
using namespace std;

/*
 * 
 */
float kineticEnergy(float mass, float velocity) {
    return 1.0 / 2.0 * mass * velocity * velocity;
}

int main(int argc, char** argv) {
    float mass, vel;
    cout << "Enter the object's mass (in kilograms): ";
    cin >> mass;
    cout << "Enter the object's velocity (in meters per second): ";
    cin >> vel;
    cout << "Kinetic energy is: " << kineticEnergy(mass, vel) << endl;
    return 0;
}

