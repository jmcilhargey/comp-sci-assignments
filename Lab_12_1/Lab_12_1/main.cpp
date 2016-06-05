//
//  main.cpp
//  Lab_12_1
//
//  Created by Joe McIlhargey on 4/10/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    
    string entry, input;
    fstream file;
    int count = 0;
    
    cout << "Enter the the file name to display the header: ";
    getline(cin, entry);
    
    file.open(entry, ios::in);
    
    if (file.fail()) {
        cout << "Unable to open the file." << endl;
    } else {
        
        while (!file.eof() && count < 10) {

            getline(file, input);
            cout << input << endl;
            count++;
        };
        
        if (file.eof()) {
            cout << "End of file. All lines displayed." << endl;
        }
        
        file.close();
    }
    
    return 0;
}
