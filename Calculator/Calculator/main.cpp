//
//  main.cpp
//  Calculator
//
//  Created by Joe McIlhargey on 5/16/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <cmath>

using namespace std;

struct FractionT {
    double numerator;
    double denominator;
    double divide();
    FractionT(double, double );
};

FractionT::FractionT(double num, double den) {
    numerator = num;
    denominator = den;
};

double FractionT::divide() {
    return numerator / denominator;
};

struct Month {
    string name;
    int days;
};

void calculator(string entry){
    
    double num1, num2;
    double total = 0;
    char oper;
    
    stringstream(entry) >> num1 >> oper >> num2;
    
    switch(oper) {
            
        case '+': total = num1 + num2;
            break;
        case '-': total = num1 - num2;
            break;
        case '*': total = num1 * num2;
            break;
        case '/': total = num1 / num2;
            break;
        default: cout << "Operator not found!" << endl;
    }
    if (total) {
        cout << "The sum is: " << total << endl;
    }
}

bool isEven(int value) {
    return !(value % 2);
}

int getTime(int hours, int mins, int secs) {
    return (hours % 12) * 3600 + mins * 60 + secs;
}

bool isPerfect(int num) {
    
    int total = 0;
    
    for (int i = 1; i < num; i++) {
        if (!(num % i)) {
            total += i;
        }
    }
    return num == total;
}

bool isPrime(int num) {
    
    bool isPrime = true;

    for (int i = 2; i < sqrt(num); i++) {
        if (!(num % i)) {
            isPrime = false;
        }
    }
    return isPrime;
}

double circleArea(double radius) {
    
    const double PI = 3.14156;
    return 0.5 * PI * pow(radius, 2);
}

int tripleByValue (int value) {
    return value * 3;
}

void tripleByReference(int &value) {
    value *= 3;
}


int main() {
    
    /*
    FractionT fraction(10, 100);
    
    cout << fraction.divide() << endl;
    
    cout << getTime(9, 30, 45) - getTime(4, 24, 20) << " seconds" << endl;
    
    for (int i = 1; i <= 1000; i++) {
        
        if (isPerfect(i)) {
            cout << i << endl;
        }
    }
    
    const int MONTHS = 12;
    string entry;
    int month;
    Month year[MONTHS] = {{"Jan", 31,}, {"Feb", 28}, {"Mar", 30}, {"Apr", 30}, {"May", 31},{"June", 30}, {"Jul", 31}, {"Aug", 31}, {"Sep", 30}, {"Oct", 31}, {"Nov", 30}, {"Dec", 31}};
    
    cout << "Enter a month number: ";
    getline(cin, entry);
    stringstream(entry) >> month;
    
    cout << "The number of days in " << year[month - 1].name << " is " << year[month - 1].days << endl;
    */
    return 0;
}
