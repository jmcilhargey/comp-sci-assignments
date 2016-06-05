//
//  main.cpp
//  Lab_12_7
//
//  Created by Joe McIlhargey on 4/11/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    
    string entry;
    fstream inFile, outFile;
    char ch;
    
    cout << "This program copies a file to another and converts to lowercase." << endl;
    
    cout << "Enter a file name to read from: ";
    getline(cin, entry);
    inFile.open(entry, ios::in);
    
    cout << "Enter a file name to write to: ";
    getline(cin, entry);
    outFile.open(entry, ios::out);
    
    if (inFile.fail()) {
        cout << "Unable to read file." << endl;
    } else {
        
        inFile.get(ch);
        outFile.put(toupper(ch));
        
        while(!inFile.eof()) {
            inFile.get(ch);
            
            if (ch == '.') {
                outFile.put(ch);
                inFile.get(ch);
                
                while(isspace(ch)) {
                    outFile.put(ch);
                    inFile.get(ch);
                }
                outFile.put(toupper(ch));
            } else {
                outFile.put(tolower(ch));
            }
        }
        inFile.close();
    }
    
    return 0;
}
