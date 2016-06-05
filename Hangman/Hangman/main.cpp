//
//  main.cpp
//  Hangman
//
//  Created by Joe McIlhargey on 4/25/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <random>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
// #include "clearscreen.h"

using namespace std;

string pickWord() {
    
    fstream wordFile;
    string str;
    int countLines = 0;
    
    wordFile.open("CommonWords.txt", ios::in);
    
    if (wordFile) {
        
        while (getline(wordFile, str)) {
            countLines++;
        }
        
        wordFile.seekg(0L, ios::beg);
        
        random_device rd;
        default_random_engine generator(rd());
        uniform_int_distribution<int> distribution(1, countLines);
        int selection = distribution(generator);
        
        for (int i = 0; getline(wordFile, str) && i < selection; i++);
    }
    
    return str;
}

void printWord(string &word, string &guesses) {
    
    cout << "SECRET WORD" << endl;
    for (int i = 0; i < word.size(); i++) {
        cout << word.at(i);
        cout << " ";
    }
    cout << endl << endl;
    cout << "GUESSES" << endl;
    for (int i = 0; i < guesses.size(); i++) {
        cout << guesses.at(i);
        cout << " ";
    }
    cout << endl << endl;
}

void printHangman(int guessCount) {
    
    switch (guessCount) {
    
        case 0: cout<<endl<<endl
    <<"   +----+     "<<endl
    <<"   |    |     "<<endl
    <<"   |          "<<endl
    <<"   |          "<<endl
    <<"   |          "<<endl
    <<"   |          "<<endl
    <<"  ============"<<endl<<endl;
            break;
        case 1: cout<<endl<<endl;
    cout<<endl<<endl
    <<"   +----+     "<<endl
    <<"   |    |     "<<endl
    <<"   |    O     "<<endl
    <<"   |          "<<endl
    <<"   |          "<<endl
    <<"   |          "<<endl
    <<"  ============"<<endl<<endl;
            break;
        case 2:
    cout<<endl<<endl
    <<"   +----+     "<<endl
    <<"   |    |     "<<endl
    <<"   |    O      "<<endl
    <<"   |    |      "<<endl
    <<"   |          "<<endl
    <<"   |          "<<endl
    <<"  ============"<<endl<<endl;
            break;
        case 3:
    cout<<endl<<endl
    <<"   +----+     "<<endl
    <<"   |    |     "<<endl
    <<"   |    O      "<<endl
    <<"   |   /|      "<<endl
    <<"   |          "<<endl
    <<"   |          "<<endl
    <<"  ============"<<endl<<endl;
            break;
        case 4:
    cout<<endl<<endl
    <<"   +----+     "<<endl
    <<"   |    |     "<<endl
    <<"   |    O     "<<endl
    <<"   |   /|\\   "<<endl
    <<"   |          "<<endl
    <<"   |          "<<endl
    <<"  ============"<<endl<<endl;
            break;
        case 5:
    cout<<endl<<endl
    <<"   +----+     "<<endl
    <<"   |    |     "<<endl
    <<"   |    O     "<<endl
    <<"   |   /|\\   "<<endl
    <<"   |   /      "<<endl
    <<"   |          "<<endl
    <<"  ============"<<endl<<endl;
            break;
        case 6:
    cout<<endl<<endl
    <<"   +----+     "<<endl
    <<"   |    |     "<<endl
    <<"   |    O     "<<endl
    <<"   |   /|\\   "<<endl
    <<"   |   / \\   "<<endl
    <<"   |Your Dead "<<endl
    <<"  ============"<<endl<<endl;
            break;
    }
}

int main() {
    
    string secretWord;
    string entry;
    string guesses = "";
    char guess;
    int guessCount = 0;
    
    secretWord = pickWord();
    string playerWord(secretWord.size(), '_');
    long remainingLetters = secretWord.size();
    
    do {
        cout << "Enter a letter to guess the character: ";
        getline(cin, entry);
        stringstream(entry) >> guess;
        
        while (guesses.find(guess) != string::npos || !isalpha(guess)) {
            cout << "Letter already guessed. Try again: ";
            getline(cin, entry);
            stringstream(entry) >> guess;
        }
        
        guesses += guess;
        
        long search = secretWord.find(guess, 0);

        if (search == string::npos) {
            guessCount++;
        } else {
            do {
                playerWord.erase(search, 1);
                playerWord.insert(search, 1, guess);
                search = secretWord.find(guess, search + 1);
                remainingLetters--;
            } while (search != string::npos);
        }
        
        // clearScreen();
        printHangman(guessCount);
        printWord(playerWord, guesses);
        
    } while (guessCount < 6 && remainingLetters > 0);
    
    if (guessCount == 6) {
        cout << "GAME OVER" << endl;
    } else {
        cout << "YOU WIN!" << endl;
    }
    
    
    return 0;
}
