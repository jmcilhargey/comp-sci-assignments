//
//  main.cpp
//  Lab_12_12
//
//  Created by Joe McIlhargey on 4/11/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

const int QUARTERS = 4, DIVISIONS = 4;

struct Division {
    string name;
    int quarter[QUARTERS];
    double sales[QUARTERS];
};

using namespace std;

int main() {
    
    Division data;
    fstream file;
    double yearTotal, minQ, maxQ;
    double qTotal[QUARTERS];
    
    cout << "Reading data from the file." << endl;
    
    file.open("sales.txt", ios::in | ios::binary);
    
    if (file) {
        file.read(reinterpret_cast<char *>(& data), sizeof(data));
        
        while(!file.eof()) {
            
            for (int i = 0; i < DIVISIONS; i++) {
                double divTotal = 0;
                
                
                
                for (int j = 0; j < QUARTERS; j++) {
                    qTotal[j] += data.sales[j];
                    yearTotal += data.sales[j];
                    divTotal += data.sales[j];
                }
                cout << "The total for " << data.name << " division is: $" << divTotal << endl;
                cout << "The average is: $" << divTotal / 4 << endl;
                file.read(reinterpret_cast<char *>(& data), sizeof(data));
            }
        }
        minQ = 1;
        maxQ = 1;
        for (int k = 0; k < QUARTERS; k++) {
            cout << "The total for Q" << k + 1 << " is: $" << qTotal[k] << endl;
            if (qTotal[k] > maxQ) {
                maxQ = k;
            } else if (qTotal[k] < minQ) {
                minQ = k;
            }
        }
        cout << "The quarter with the least sales is Q" << minQ << endl;
        cout << "The quarter with the most sales is Q" << maxQ << endl;
        cout << "The total corporate sales are: $" << yearTotal << endl;
        
        file.close();
    } else {
        cout << "Error opening file." << endl;
    }
    
    return 0;
}
