/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Employee.h
 * Author: admin
 *
 * Created on May 3, 2017, 12:25 AM
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee {
private:
    string name;
    int idNumber;
    string department;
    string position;
public:
    Employee(string, int, string, string);
    Employee(string, int);
    Employee();
    void SetPosition(string);

    string GetPosition() const;

    void SetDepartment(string);

    string GetDepartment() const;

    void SetIdNumber(int);

    int GetIdNumber() const;

    void SetName(string);

    string GetName() const;
};

#endif /* EMPLOYEE_H */

