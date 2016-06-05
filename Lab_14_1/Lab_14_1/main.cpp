//
//  main.cpp
//  Lab_14_1
//
//  Created by Joe McIlhargey on 5/26/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;



class Date {
public:
    int month;
    int day;
    int year;
    void printDate1();
    void printDate2(const string []);
    void printDate3(const string []);
};

void Date::printDate1() {
    cout << month << "\\" << day << "\\" << year << endl;
}

void Date::printDate2(const string months[]) {
    cout << months[month - 1] << " " << day << ", " << year << endl;
}

void Date::printDate3(const string months[]) {
    cout << day << " " << months[month - 1] << " " << year << endl;
}

int main() {
    
    const string months[12] = {"January", "February", "March", "April", "May", "June", "July", "September", "October", "November", "December"};
    
    string entry;
    Date date;
    
    cout << "Enter a date to print in format, mm dd yyyy: ";
    getline(cin, entry);
    
    stringstream(entry) >> date.month >> date.day >> date.year;
    
    date.printDate1();
    date.printDate2(months);
    date.printDate3(months);
    
    return 0;
}
