//
//  main.cpp
//  Lab_12_11
//
//  Created by Joe McIlhargey on 4/11/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

const int QUARTERS = 4, DIVISIONS = 4;

struct Division {
    string name;
    int quarter[QUARTERS];
    double sales[QUARTERS];
};

int main() {
    
    fstream file;
    string entry;
    Division data;
    
    file.open("sales.txt", ios::out | ios::binary);
    
    cout << "Enter the sales data for each division." << endl;

    for (int i = 0; i < DIVISIONS; i++) {
        cout << "Division name: ";
        cin.ignore();
        getline(cin, data.name);
        
        for (int j = 0; j < QUARTERS; j++){
            data.quarter[j] = j + 1;
            cout << "Enter sales for quarter #" << j + 1 << ": ";
            cin >> data.sales[j];
        }
        
        file.write(reinterpret_cast<char *>(&data), sizeof(data));
        file.close();
    }
    
    return 0;
}
