//
//  main.cpp
//  Tic_Tac_Toe
//
//  Created by Joe McIlhargey on 5/16/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cctype>

using namespace std;

void loadBooks(vector<string> &books) {
    
    fstream file;
    string book;
    
    file.open("textbooks.txt", ios::in);
    
    if (file) {
        while (getline(file, book)) {
            books.push_back(book);
        }
        
        file.close();
    } else {
        cout << "Error loading file" << endl;
    }
}

void searchBooks(vector<string> &books, vector<string> &results, string search) {
    
    for (string book : books) {
        
        if (book.find(search) != string::npos || book.find(static_cast<char>(toupper(search.at(0))) + search.substr(1)) != string::npos) {
            results.push_back(book);
        }
    }
}


int main() {
    
    vector<string> textbooks, results;
    string entry, select;
    
    loadBooks(textbooks);
    
    do {
        
        cout << "Enter a phrase to search the books list: ";
        getline(cin, entry);
        
        searchBooks(textbooks, results, entry);
        
        for (string result : results) {
            cout << result << endl;
        }
        
        results.clear();
        
        cout << "Search again? (y/n): ";
        getline(cin, select);
        
    } while (select != "n");
    
    return 0;
}