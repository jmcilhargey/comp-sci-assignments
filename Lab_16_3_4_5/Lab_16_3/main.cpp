//
//  main.cpp
//  Lab_16_3
//
//  Created by Joe McIlhargey on 5/28/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

template <class T>
T getMax(T num1, T num2) {
    return num1 > num2 ? num1 : num2;
}

template <class T>
T getMin(T num1, T num2) {
    return num1 < num2 ? num1 : num2;
}

template <class T>
T getAbsVal(T num) {
    return num < 0 ? -1 * num : num;
}

template <class T>
T calcTotal(T nums) {
    
    string entry;
    T total = 0;
    T amount;
    
    for (int i = 0; i < nums; i++) {
        cout << "Enter the amount for value #" << i + 1 << ": ";
        getline(cin, entry);
        stringstream(entry) >> amount;
        total += amount;
    }
    return total;
}

int main() {
    
    cout << getMax(5, 4) << endl;
    cout << getMax(8.5, 9.0) << endl;
    cout << getMax("hello", "there") << endl;
    
    cout << getMin(7, 0) << endl;
    cout << getMin(2.5, 9.5) << endl;
    cout << getMin("hello", "there") << endl;
    
    cout << getAbsVal(-3.5) << endl;
    cout << getAbsVal(7) << endl;
    
    cout << calcTotal(5) << endl;
    
    return 0;
}
