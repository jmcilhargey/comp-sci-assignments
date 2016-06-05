//
//  main.cpp
//  Binary_Converter
//
//  Created by Joe McIlhargey on 6/4/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <cmath>
#include <cctype>

using namespace std;

int digitFromValue(char c) {
    
    int value;
    
    if (isalpha(c)) {
        value = c - 'A' + 10;
    } else {
        value = c - '0';
    }
    
    return value;
}

int convertFromBase(string number, int base) {
    
    int total = 0;
    
    for (long i = number.length() - 1; i >= 0; i--) {
        
        int digit = digitFromValue(number.at(i));
        long exp = number.length() - 1 - i;
        
        total += digit * pow(base, exp);
    }
    
    return total;
}

bool compareBinToHex(string binStr, string hexStr) {
    
    int binNum = convertFromBase(binStr, 2);
    int hexNum = convertFromBase(hexStr, 16);
    
    if (hexNum < 0 || binNum < 0) {
        return false;
    }
    
    return binNum == hexNum;
}

int main() {
    
    cout << compareBinToHex("1001101011", "26B") << endl;
    
    return 0;
}