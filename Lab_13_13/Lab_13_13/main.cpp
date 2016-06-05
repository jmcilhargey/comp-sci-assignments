//
//  main.cpp
//  Lab_13_13
//
//  Created by Joe McIlhargey on 4/30/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <random>
#include <iomanip>

using namespace std;

class Coin {
private:
    string sideUp;
public:
    Coin();
    void toss();
    string getSideUp();
};

Coin::Coin() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis (0, 1);
    int flip = dis(gen);
    
    flip == 1 ? sideUp = "heads" : sideUp = "tails";
}

void Coin::toss() {
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis (0, 1);
    int flip = dis(gen);
    
    flip == 1 ? sideUp = "heads" : sideUp = "tails";
};

string Coin::getSideUp() {
    return sideUp;
};

int main() {
    
    Coin quarter;
    Coin dime;
    Coin nickel;
    
    double balance = 0;
    
    while (balance < 1) {
        quarter.toss();
        dime.toss();
        nickel.toss();
        
        if (quarter.getSideUp() == "heads") {
            balance += 0.25;
        } else if (dime.getSideUp() == "heads") {
            balance += 0.10;
        } else if (nickel.getSideUp() == "heads") {
            balance += 0.05;
        }
    }
    cout << setprecision(2) << fixed << showpoint;
    cout << "Your final balance is: $" << balance << endl;
    
    balance == 1 ? cout << "You win!" << endl : cout << "You lose!" << endl;
    
    return 0;
}
