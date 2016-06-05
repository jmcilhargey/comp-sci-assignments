//
//  main.cpp
//  RLE_Encrypt
//
//  Created by Joe McIlhargey on 5/18/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main() {
    
    string inFileName, line;
    fstream inFile, outFile;
    char currChar, nextChar;
    
    cout << "Enter the name of a file to encrypt: ";
    getline(cin, inFileName);

    inFile.open(inFileName, ios::in);
    
    string outFileName = inFileName.insert(inFileName.find('.'), ".RLE");
    
    outFile.open(outFileName, ios::out);
    
    
    if (inFile) {
    
        while (getline(inFile, line)) {
            
            int charCount = 0;
            
            for (int i = 0; i < line.length() - 1; i++) {
                currChar = line.at(i);
                nextChar = line.at(i + 1);
                
                if (isalpha(currChar)) {
                    charCount++;
                    
                    if (currChar != nextChar) {
                        outFile << currChar;
                        outFile << charCount;
                        charCount = 0;
                    }
                }
            }
            outFile << '\n';
        }
        
        inFile.close();
        outFile.close();
        
    } else {
        cout << "Error opening file." << endl;
    }
    
    return 0;
}
