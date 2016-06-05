/***************************************************************
 Problem: Structures 11.2
 Description: This program calculates the tax data for individuals using structures
 Name: Joe McIlhargey
 NameID: 1588297
 Date: 4/18/16
 Status: Complete
 ****************************************************************/

#include <iostream> 
#include <string> 
#include <iomanip>
#include <sstream>

using namespace std;

struct taxPayer {
    string name;
    long socialSecNum;
    float taxRate;
    float income;
    float taxes;
};

int main() {
    
    taxPayer citizen1 {"Tim McGuiness", 255871234, 0.35};
    taxPayer citizen2 {"John Kane", 278990582, 0.29};
    
    string entry;
    
    cout << fixed << showpoint << setprecision(2);
    cout << "Enter the income for " << citizen1.name << ": ";
    getline(cin, entry);
    stringstream(entry) >> citizen1.income;
    citizen1.taxes = citizen1.income * citizen1.taxRate;
    
    cout << "Name: " << citizen1.name << endl;
    cout << "Social Security Number: " << citizen1.socialSecNum << endl;
    cout << "Taxes due for this year: $" << citizen1.taxes << endl << endl;
    
    cout << "Enter the income for " << citizen2.name << ": ";
    getline(cin, entry);
    stringstream(entry) >> citizen2.income;
    citizen2.taxes = citizen2.income * citizen2.taxRate;
    
    cout << "Name: " << citizen2.name << endl;
    cout << "Social Security Number: " << citizen2.socialSecNum << endl;
    cout << "Taxes due for this year: $" << citizen2.taxes << endl << endl;
    
    return 0;
}