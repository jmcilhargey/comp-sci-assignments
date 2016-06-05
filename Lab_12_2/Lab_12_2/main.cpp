//
//  main.cpp
//  Lab_12_2
//
//  Created by Joe McIlhargey on 4/10/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    
    fstream file;
    string entry, input;
    int count = 1;
    
    cout << "Enter a file name to read: ";
    getline(cin, entry);
    
    file.open(entry, ios::in);
    
    if (file.fail()) {
        cout << "Error, unable to open file." << endl;
    } else {
        
        while (!file.eof()) {
            getline(file, input, '\n');
            cout << input << endl;
            count++;
            
            if (count % 24 == 0) {
                cout << "*** Paused, press any key to continue ***";
                cin.get();
            }
        }
        file.close();
    }
    
    return 0;
}
