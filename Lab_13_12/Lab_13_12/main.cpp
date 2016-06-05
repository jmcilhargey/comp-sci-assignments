//
//  main.cpp
//  Lab_13_12
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
    
    Coin coin;
    const int TURNS = 20;
    
    cout << "The initial side is: " << coin.getSideUp() << endl;
    
    for (int i = 0; i < TURNS; i++) {
        coin.toss();
        cout << "For turn #" << i + 1 << " the side is: " << coin.getSideUp() << endl;
    }
    
    return 0;
}