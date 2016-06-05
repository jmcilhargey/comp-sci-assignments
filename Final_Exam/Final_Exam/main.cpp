//
//  main.cpp
//  Final_Exam
//
//  Created by Joe McIlhargey on 5/23/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <vector>
#include <sstream>
#include <string>
#include <iomanip>

using namespace std;

int sum_positive(vector<int> &vector) {

    int total = 0;
    bool isPositive;
    
    for (int num : vector) {
        isPositive = num > 0;
        total += num * isPositive;
    }
    return total;
}

vector<int> myCount(string str) {

    vector<int> vect(10);
    
    for (int i = 0; i < str.length(); i++) {
        if (isdigit(str.at(i))) {
            vect.at(str.at(i) - '0')++;
        }
    }
    return vect;
}

void print(vector<int> vect) {
    
    for (int i = 0; i < vect.size(); i++) {
        cout << "Count of " << i << "s is " << vect.at(i) << endl;
    }
}

void getDigitAndAdd(string listOfNums) {

    stringstream stream(listOfNums);
    double currNum;
    double total = 0;
    
    while (stream >> currNum) {
        cout << setprecision(1) << fixed;
        total += currNum;
    }
    cout << total << endl;
}

void getDaysOfMonth (int month, int year) {

    const int MONTHS = 12;
    int days;
    string names[MONTHS] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    
    if (month > 2) {
        (month - 2) % 5 % 2 ? days = 31 : days = 30;
    } else if (month == 2) {
        year % 4 ? days = 28 : days = 29;
    } else {
        days = 31;
    }
    cout << names[month - 1] << " " << year << " has " << days << " days." << endl;
}

bool isAnE (char ch) {
    return ch == letter;
}

int main() {
    
    string s1 ("hello there");
    string s2 ("the brown fox jumped on the fence");
    int s1count = 0;
    int s2count = 0;
    const char letter = 'e';
    long found = -1;
    stringstream ss;
    
    
    
    s1count += isAnE(str.at(i));
    
    for (int i = 0; s1.length())
        
        /*
    string entry;
    
    cout << "Enter a string to test: ";
    getline(cin, entry);
    
    vector<int> v = myCount(entry);
    print(v);
    

    string entry;
    int month;
    int year;
    
    cout << "Enter the year and month as digits: ";
    getline(cin, entry);
    stringstream(entry) >> month >> year;
    cout << month << endl;
    cout << year << endl;
    
    getDaysOfMonth(month, year);
    
    
    string entry;
    cout << "Enter a set of numbers to calculate: ";
    getline(cin, entry);
    
    getDigitAndAdd(entry);

    

    
    //vector<int> v = {-2, 5, 0, 4, 10, -2, 4};
    // cout << sum_positive(v);
    
    

    do {
        found = s1.find(letter, found + 1);
        s1count++;
        
    } while (found != string::npos);
    
    do {
        found = s2.find(letter, found + 1);
        s2count++;
        
    } while (found != string::npos);
    
    cout << "count is : "<<s1count<<" and "<<s2count<<endl;
     
     */
}



