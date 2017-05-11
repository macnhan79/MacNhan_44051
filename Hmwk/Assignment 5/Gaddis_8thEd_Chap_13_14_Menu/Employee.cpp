/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
#include "Employee.h"

Employee::Employee(string name, int id, string department, string position) {
    this->name = name;
    this->idNumber = id;
    this->department = department;
    this->position = position;
}

Employee::Employee(string name, int id) {
    this->name = name;
    this->idNumber = id;
    this->department = "";
    this->position = "";
}

Employee::Employee() {
    this->name = "";
    this->idNumber = 0;
    this->department = "";
    this->position = "";
}

void Employee::SetPosition(string position) {
    this->position = position;
}

string Employee::GetPosition() const {
    return position;
}

void Employee::SetDepartment(string department) {
    this->department = department;
}

string Employee::GetDepartment() const {
    return department;
}

void Employee::SetIdNumber(int idNumber) {
    this->idNumber = idNumber;
}

int Employee::GetIdNumber() const {
    return idNumber;
}

void Employee::SetName(string name) {
    this->name = name;
}

string Employee::GetName() const {
    return name;
}