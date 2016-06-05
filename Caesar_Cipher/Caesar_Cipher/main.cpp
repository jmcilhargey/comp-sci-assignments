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

void encrypt (int shift) {

    string str;
    fstream inFile, outFile;
    
    inFile.open("message.txt", ios::in);
    
    if (!inFile.fail()) {
        outFile.open("encrypted.txt", ios::out);
        
        while (!inFile.eof()) {
            
            getline(inFile, str);
            for (int i = 0; i < str.size(); i++) {
                
                if (isalpha(str.at(i))) {
                    outFile.put(static_cast<char>((tolower(str.at(i)) - 'a' + shift) % 26 + 'a'));
                } else if (isdigit(str.at(i))) {
                    outFile.put(static_cast<char>(str.at(i) - '0' + shift) % 10 + '0');
                } else {
                    outFile.put(str.at(i));
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

void decrypt (int shift) {
    
    string str;
    fstream inFile, outFile;
    
    inFile.open("encrypted.txt", ios::in);
    
    if (!inFile.fail()) {
        
        outFile.open("decrypted.txt", ios::out);
        
        while(!inFile.eof()) {
            
            getline(inFile, str);
            for (int i = 0; i < str.size(); i++) {
                
                if (isalpha(str.at(i))) {
                    cout << static_cast<char>((tolower(str.at(i)) - 'a' + 26 - shift) % 26 + 'a');
                    outFile.put(static_cast<char>((tolower(str.at(i)) - 'a' + 26 - shift) % 26 + 'a'));
                } else if (isdigit(str.at(i))) {
                    cout << static_cast<char>(str.at(i) - '0' + 10 - shift) % 10 + '0';
                    outFile.put(static_cast<char>(str.at(i) - '0' + 10 - shift) % 10 + '0');
                } else {
                    cout << str.at(i);
                    outFile.put(str.at(i));
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
    int shift;
 
    cout << "1. Encrypt" << endl;
    cout << "2. Decrypt" << endl;
    cout << "Select option: ";
    getline(cin, option);
    
    cout << "Enter the shift: ";
    getline(cin, input);
    stringstream(input) >> shift;
    
    if (option == "1") {
        encrypt(shift);
    } else if (option == "2") {
        decrypt(shift);
    }
    
    return 0;
}