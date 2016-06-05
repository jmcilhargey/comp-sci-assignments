//
//  main.cpp
//  Lab_12_13
//
//  Created by Joe McIlhargey on 4/11/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

void addRecord (fstream & );
void showRecord (fstream & );
void editRecord (fstream & );

struct Item {
    string description;
    int quantity;
    double costWholesale;
    double costRetail;
    string dateAdded;
};

int main() {
    
    fstream file;
    int selection;
    
    do {
        cout << "1 - Add new record to file" << endl;
        cout << "2 - Display record on file" << endl;
        cout << "3 - Update record on file" << endl;
        cout << "4 - Exit system" << endl;
        cout << "Enter your selection: ";
        cin >> selection;
        
        switch(selection) {
            case 1: addRecord(file);
                break;
            case 2: showRecord(file);
                break;
            case 3: editRecord(file);
                break;
            case 4: cout << "Exiting system." << endl;
                break;
        }
        
    } while (selection != 4);
    
    return 0;
}

void addRecord (fstream &file) {
    
    Item item;
    file.open("stock.txt", ios::out | ios::app | ios::binary);
    
    cout << "Enter a description: ";
    cin.ignore();
    getline(cin, item.description);
    cout << "Enter the quantity: ";
    cin >> item.quantity;
    cout << "Enter the wholesale cost: ";
    cin >> item.costWholesale;
    cout << "Enter the retail cost: ";
    cin >> item.costRetail;
    cout << "Enter the date added (mm/dd/yy): ";
    cin.ignore();
    getline(cin, item.dateAdded);
    
    file.write(reinterpret_cast<char *>(& item), sizeof(item));
    file.close();
}

void showRecord (fstream &file) {
    
    Item item;
    file.open("stock.txt", ios::in);
    file.read(reinterpret_cast<char *>(&item), sizeof(item));
    
    while (!file.eof()) {
        
        cout << "Description:\t" << item.description << endl;
        cout << "Quantity:\t" << item.quantity << endl;
        cout << "Wholesale cost:\t" << item.costWholesale << endl;
        cout << "Retail cost:\t" << item.costRetail << endl;
        cout << "Date added:\t" << item.dateAdded << endl;
        
        file.read(reinterpret_cast<char *>(&item), sizeof(item));
    }
    file.close();
}

void editRecord (fstream &file) {
    Item item;
    int num;
    
    cout << "Enter a record number to edit: ";
    cin >> num;
    
    file.open("stock.txt", ios::in | ios::out);
    file.seekg(sizeof(item) * (num - 1), ios::beg);
    
    cout << "Enter new information for record #" << num << endl;
    cout << "Enter a description: ";
    cin.ignore();
    getline(cin, item.description);
    cout << "Enter the quantity: ";
    cin >> item.quantity;
    cout << "Enter the wholesale cost: ";
    cin >> item.costWholesale;
    cout << "Enter the retail cost: ";
    cin >> item.costRetail;
    cout << "Enter the date added (mm/dd/yy): ";
    cin.ignore();
    getline(cin, item.dateAdded);
    
    file.write(reinterpret_cast<char *>(& item), sizeof(item));
    file.close();
}
