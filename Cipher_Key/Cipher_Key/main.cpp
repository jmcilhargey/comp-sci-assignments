/***************************************************************
 Problem: Caesar's Cypher - Team Homework
 Description: This program takes a string input and a shift amount and outputs either the encryption or decryption.
 Name: Joe McIlhargey & Chen Chen
 NameID: 1588297 & 1482468
 Date: 4/18/16
 Status: Complete
 ****************************************************************/

#include <iostream>
#include <string>
#include <cctype>
#include <sstream>
#include <fstream>

using namespace std;

void encrypt () {
    
    string str, key;
    fstream inFile, keyFile, outFile;
    
    inFile.open("message.txt", ios::in);
    keyFile.open("key.txt", ios::in);
    
    if (!inFile.fail()) {
        outFile.open("encrypted.txt", ios::out);
        
        getline(keyFile, key);
        getline(keyFile, key);
        
        while (!inFile.eof()) {
            
            getline(inFile, str);
            for (char ch : str) {
                if (isalpha(ch)) {
                    outFile.put(key.at(tolower(ch) - 'a'));
                } else {
                    outFile.put(ch);
                }
            }
        }
        cout << "Encryption complete and data written to file." << endl;
        
        inFile.close();
        outFile.close();
        
    } else {
        cout << "Unable to open file." << endl;
    }
}

void decrypt () {
    
    string str, key;
    fstream inFile, keyFile, outFile;
    
    inFile.open("encrypted.txt", ios::in);
    keyFile.open("key.txt", ios::in);
    
    if (!inFile.fail()) {
        
        outFile.open("decrypted.txt", ios::out);
        
        getline(keyFile, key);
        getline(keyFile, key);
        while(!inFile.eof()) {
            
            getline(inFile, str);
            for (char ch : str) {
                
                if (isalpha(ch)) {
                    outFile.put(key.find(ch) + 'a');
                } else {
                    outFile.put(ch);
                }
            }
            cout << endl;
        }
        cout << "Decryption complete and data written to file." << endl;
        
        inFile.close();
        outFile.close();
        
    } else {
        cout << "Unable to open file." << endl;
    }
}

int main() {
    
    string input, option;
    
    cout << "1. Encrypt" << endl;
    cout << "2. Decrypt" << endl;
    cout << "Select option: ";
    getline(cin, option);
    
    if (option == "1") {
        encrypt();
    } else if (option == "2") {
        decrypt();
    }
    
    return 0;
}