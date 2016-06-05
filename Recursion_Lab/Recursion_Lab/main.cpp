/***************************************************************
 Problem: Recursion Lab
 Description: This is a lab for building recursive functions.
 Name: Joe McIlhargey
 NameID: 1588297
 Date: 5/9/16
 Status: Complete
 ****************************************************************/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

double sumSeries(double num) {
    
    if (num < 0) {
        cout << "Error, number must be greater than 0" << endl;
    }
    
    if (num == 0) {
        return 0;
    } else {
        return sumSeries(num - 1) + num / (2 * num + 1);
    }
}

void reverseDisplay(int value) {
    
    if (value < 0) {
        cout << "Error, number must be greater than 0" << endl;
    }
    
    if (value < 10) {
        cout << value << endl;
    } else {
        cout << value % 10;
        return reverseDisplay(value / 10);
    }
}

int countChar(const string &str, char ch) {
    
    if (str.size() == 0) {
        return 0;
    } else {
        if (str.at(0) == ch) {
            return countChar(str.substr(1), ch) + 1;
        }
        return countChar(str.substr(1), ch);
    }
}

void reverseDisplay(const string &str) {
    
    if (str.size() == 0) {
        cout << endl;
    } else {
        cout << str.at(str.size() - 1);
        reverseDisplay(str.substr(0, str.size() - 1));
    }
    
}

int main() {
    
    string entry, searchStr, flipStr;
    double numIterations;
    int reverseInt;
    char findCh;

    cout << "Enter a number to calculate the sum series: ";
    getline(cin, entry);
    stringstream(entry) >> numIterations;
    
    cout << "The total is: " << sumSeries(numIterations) << endl;
    
    cout << "Enter a number to print the reverse: ";
    getline(cin, entry);
    stringstream(entry) >> reverseInt;
    
    reverseDisplay(reverseInt);
    
    cout << "Enter a string: ";
    getline(cin, searchStr);
    cout << "Enter a character to check occurances: ";
    getline(cin, entry);
    stringstream(entry) >> findCh;
    
    cout << "Number of occurances is: " << countChar(searchStr, findCh) << endl;

    cout << "Enter a string to reverse: ";
    getline(cin, flipStr);
    
    reverseDisplay(flipStr);
    
    return 0;
}
