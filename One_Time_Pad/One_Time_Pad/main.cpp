/***************************************************************
 Problem: One Time Pad - Team Homework
 Description: This program opens a file, reads the text, encrypts the text with a dictionary "one time pad," and then saves the encrypted text to a new file. The program can also decrypt encrypted files by performing the reverse.
 Name: Joe McIlhargey & Chen Chen
 NameID: 1588297 & 1482468
 Date: 4/23/16
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
    fstream inFile, padFile, outFile;
    char letter;
    
    inFile.open("text.txt", ios::in);
    padFile.open("dictionary.txt", ios::in);
    
    if (!inFile.fail() && !padFile.fail()) {
        outFile.open("message.txt", ios::out);

        getline(inFile, str);
        
        while (!inFile.eof()) {

            for (char ch : str) {
                if (isalpha(ch)) {
                    do {
                        letter = static_cast<char>(padFile.get());
                    } while (!isalpha(letter));
                    outFile.put((tolower(ch) + letter - 2 * 'a') % 26 + 'a');
                } else {
                    outFile.put(ch);
                }
            }
            getline(inFile, str);
        }
        cout << "Encryption complete and data written to file." << endl;
        
        inFile.close();
        padFile.close();
        outFile.close();
        
    } else {
        cout << "Unable to open file." << endl;
    }
}

void decrypt () {

    string str, key, line;
    fstream inFile, padFile, outFile;
    char letter;
    
    inFile.open("message.txt", ios::in);
    padFile.open("dictionary.txt", ios::in);
    
    if (!inFile.fail() && !padFile.fail()) {
        
        outFile.open("decrypted.txt", ios::out);
        
        while (!inFile.eof()) {
            
            getline(inFile, str);
            for (char ch : str) {
                
                if (isalpha(ch)) {
                    do {
                        letter = static_cast<char>(padFile.get());
                    } while (!isalpha(letter));
                    outFile.put((tolower(ch) - letter + 26) % 26 + 'a');
                } else {
                    outFile.put(ch);
                }
            }
        }
        cout << "Decryption complete and data written to file." << endl;
        
        inFile.close();
        padFile.close();
        outFile.close();
        
    } else {
        cout << "Unable to open file." << endl;
    }
}

int main() {
    
    string input, entry;
    int select;
    
    do {

        cout << "1. Encrypt" << endl;
        cout << "2. Decrypt" << endl;
        cout << "3. Exit" << endl;
        cout << "Select option: ";
        getline(cin, entry);
        stringstream(entry) >> select;
        
        switch (select) {
            case 1: encrypt();
                break;
            case 2: decrypt();
                break;
        }
    } while (select != 3);
    
    return 0;
}