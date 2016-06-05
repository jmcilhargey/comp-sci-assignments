//
//  main.cpp
//  Lab_13_2
//
//  Created by Joe McIlhargey on 5/26/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;



class Employee {
private:
    string name;
    int idNumber;
    string department;
    string position;
public:
    string getName();
    int getId();
    string getDept();
    string getPos();
    void setName(string );
    void setId(int );
    void setDept(string );
    void setPos(string );
    Employee(string , int , string , string );
    Employee(string , int );
    Employee();
};

string Employee::getName() {
    return name;
}

int Employee::getId() {
    return idNumber;
}

string Employee::getDept() {
    return department;
}

string Employee::getPos() {
    return position;
}

void Employee::setName(string empName) {
    name = empName;
}

void Employee::setId(int empId) {
    idNumber = empId;
}

void Employee::setDept(string empDept) {
    department = empDept;
}

void Employee::setPos(string empPos) {
    position = empPos;
}

Employee::Employee(string empName, int empId, string empDept, string empPos) {
    name = empName;
    idNumber = empId;
    department = empDept;
    position = empPos;
}

Employee::Employee(string empName, int empId) {
    name = empName;
    idNumber = empId;
    department = "";
    position = "";
}

Employee::Employee() {
    name = "";
    idNumber = 0;
    department = "";
    position = "";
}

void printEmp(Employee emp) {

    cout << setw(15) << emp.getName() << setw(15) << emp.getId() << setw(15) << emp.getDept() << setw(15) << emp.getPos() << endl;
}

int main() {
    
    Employee emp1("Susan Meyers", 47899, "Accounting", "Vice President");
    Employee emp2("Mark Jones", 39119, "IT", "Programmer");
    Employee emp3("Joy Rogers", 81774, "Manufacturing", "Engineer");
    
    printEmp(emp1);
    printEmp(emp2);
    printEmp(emp3);
    
    return 0;
}