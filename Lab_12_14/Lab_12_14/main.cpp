//
//  main.cpp
//  Lab_12_14
//
//  Created by Joe McIlhargey on 4/11/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

struct Item {
    string description;
    int quantity;
    double costWholesale;
    double costRetail;
    string dateAdded;
};

int main() {
    
    string name;
    fstream file;
    Item item;
    
    cout << "This program reads the stock file and displays info." << endl;
    cout << "Enter the name of the file to open: ";
    getline(cin, name);
    
    file.open(name, ios::in);
    
    if (file.fail()) {
        cout << "Error, problem opening file." << endl;
    } else {
    
        double wholesaleTotal, retailTotal, quantityTotal;
        
        file.read(reinterpret_cast<char *>(& item), sizeof(item));
        
        while(!file.eof()) {
            wholesaleTotal += item.costWholesale;
            retailTotal += item.costRetail;
            quantityTotal += item.quantity;
            
            file.read(reinterpret_cast<char *>(& item), sizeof(item));
        }
        file.close();
        
        cout << "The total wholesale cost is: " << wholesaleTotal << endl;
        cout << "The total retail cost is: " << retailTotal << endl;
        cout << "The total quantity is: " << quantityTotal << endl;
    }
    
    return 0;
}