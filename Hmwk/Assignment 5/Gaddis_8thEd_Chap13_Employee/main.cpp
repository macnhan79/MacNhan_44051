/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: admin
 *
 * Created on May 3, 2017, 12:11 AM
 */

#include <cstdlib>
#include "Employee.h"
#include <string>
#include <iostream>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Employee *emp = new Employee[3];
    //input employee 1
    emp[0].SetName("Susan Meyers");
    emp[0].SetIdNumber(47899);
    emp[0].SetDepartment("Accouting");
    emp[0].SetPosition("Vice President");
    //input employee 2
    emp[1].SetName("Mark Jones");
    emp[1].SetIdNumber(39119);
    emp[1].SetDepartment("IT");
    emp[1].SetPosition("Programmer");
    //input employee 3
    emp[2].SetName("Joy Rogers");
    emp[2].SetIdNumber(81774);
    emp[2].SetDepartment("Manufacturing");
    emp[2].SetPosition("Engineer");
    //print employee
    cout << "Name\t\tID number\t\tDepartment\t\tPosition" << endl;
    cout << "--------------------------------------------------------------" << endl;
    for (int i = 0; i < 3; i++) {
        cout << emp[i].GetName() << "\t\t"
                << emp[i].GetIdNumber() << "\t\t"
                << emp[i].GetDepartment() << "\t\t"
                << emp[i].GetPosition() << endl;
    }
    //delete employee
    delete []emp;
    return 0;
}

