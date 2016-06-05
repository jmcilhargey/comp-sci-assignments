/***************************************************************
 Problem: Structures 11.3
 Description: This program calculates the tax data for individuals using structures
 Name: Joe McIlhargey
 NameID: 1588297
 Date: 4/18/16
 Status: Complete
 ****************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

struct taxPayer {
    double taxRate;
    double income;
    double taxes;
};

int main() {
    
    const int SIZE = 5;
    taxPayer citizen[SIZE];
    string entry;
    
    cout << fixed << showpoint << setprecision(2);
    
    cout << "Please enter the annual income and tax rate for 5 tax payers: ";
    cout << endl << endl;
    
    for (int count = 0; count < SIZE; count++) {
        cout << "Enter this year's income for tax payer " << (count + 1);
        cout << ": ";
        getline(cin, entry);
        stringstream(entry) >> citizen[count].income;
        
        cout << "Enter the tax rate for tax payer # " << (count + 1);
        cout << ": ";
        getline(cin, entry);
        stringstream(entry) >> citizen[count].taxRate;
        
        citizen[count].taxes = citizen[count].income * citizen[count].taxRate;
        cout << endl;
    }
    cout << "Taxes due for this year: " << endl << endl;
    
    for (int index = 0; index < SIZE; index++) {
        cout << "Tax Payer # " << (index + 1) << ": " << "$ "
        << citizen[index].taxes << endl;
    }
    
    return 0;
}
