//
//  main.cpp
//  Lab_19_1
//
//  Created by Joe McIlhargey on 5/28/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <iomanip>
#include <cctype>

using namespace std;

double factorialIterative(int num) {
    
    double total = 1;
    
    for (int i = num; i > 0; i--) {
        total *= i;
    }
    return total;
}

void signRecursive(int num) {
    
    if (num <= 0) {
        return;
    }
    cout << "No Parking!\n";
    
    signRecursive(num - 1);
}

double arraySumRecursive(double array[], int size) {

    double total = array[size - 1];
    
    if (size <= 0) {
        return total;
    }

    return total + arraySumRecursive(array, size - 1);
}

double powerRecursive(double num, int exp) {

    double total = num;
    
    if (exp == 1) {
        return total;
    }
    
    return total * powerRecursive(num, exp - 1);
}

bool palindromeRecursive(string str) {
    
    if (str.length() <= 1) {
        return true;
    }
    
    long firstIndex = 0;
    long lastIndex = str.length() - 1;
    
    char firstChar = str.at(firstIndex);
    char lastChar = str.at(lastIndex);
    
    while (!isalpha(firstChar)) {
        firstIndex++;
        firstChar = str.at(firstIndex);
    }
    
    while (!isalpha(lastChar)) {
        lastIndex--;
        lastChar = str.at(lastIndex);
    }
    
    if (tolower(str.at(0)) == tolower(str.at(str.length() - 1))) {
        palindromeRecursive(str.substr(1, str.length() - 2));
    }
    return true;
}

int main() {
    
    const int SIZE = 7;
    double numArr[SIZE] = {4, 6, 3, 2, 1, 7, 9};
    string entry;
    
    cout << setprecision(10);
    
    cout << factorialIterative(5) << endl;
    cout << factorialIterative(10) << endl;
    
    signRecursive(5);
    
    cout << "Sum of array is: " << arraySumRecursive(numArr, SIZE) << endl;
    cout << "3 to the power of 4 is: " << powerRecursive(3, 4) << endl;
    
    cout << "Enter a string to check if palindrome: ";
    getline(cin, entry);
    if (palindromeRecursive(entry)) {
        cout << "Yes, it's a palindrome" << endl;
    } else {
        cout << "Not a palindrome" << endl;
    }
    
    return 0;
}
