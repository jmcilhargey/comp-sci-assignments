//
//  main.cpp
//  Lab_12_4
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
    char ch;
    fstream file;
    int lines = 0;
    
    cout << "Enter the name of a file to read last lines: ";
    getline(cin, entry);
    
    file.open(entry, ios::in);
    
    if (file.fail()) {
        cout << "Unable to open file." << endl;
    } else {
        
        while (!file.eof()) {
            file.get(ch);
            if (ch == '\n') {
                lines++;
            }
        }
        file.clear();
        file.seekg(0L, ios::beg);
        
        if (lines <= 10) {
            while (!file.eof()) {
                getline(file, input, '\n');
                cout << input << endl;
            }
        } else {
            while (!file.eof()) {
                file.get(ch);
                if (ch == '\n') {
                    lines--;
                }
                if (lines < 10) {
                    cout << ch;
                }
            }
        }
    }
    
    cout << lines << endl;
    file.close();
    
    return 0;
}
