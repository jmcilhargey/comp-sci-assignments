//
//  main.cpp
//  Soccer_Scores
//
//  Created by Joe McIlhargey on 4/13/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

struct Player {
    string name;
    int number;
    int points;
    void addPoints(int p) {
        points += p;
    };
};

int main() {
    
    const int PLAYERS = 5;
    
    vector<Player> team;
    string entry;
    
    for (int i = 0; i < PLAYERS; i++) {
        cout << "Enter the player name: ";
        getline(cin, team[i].name);
        cout << "Enter the player number: ";
        getline(cin, entry);
        stringstream(entry) >> team[i].number;
        cout << "Enter the player points: ";
        getline(cin, entry);
        stringstream(entry) >> team[i].points;
    }
    
    int max = team[0].points;
    string name = team[0].name;
    int total = 0;
    
    cout << "Name" << setw(10) << "Number" << setw(10) << "Points" << setw(10) << endl;
    
    for (Player player : team) {
        
    cout << player.name << setw(10) << player.number << setw(10) << player.points << setw(10) << endl;
        
        if (max < player.points){
            max = player.points;
            name = player.name;
        }
        total += player.points;
    }
    
    cout << "The total points: " << total << endl;
    cout << "Player " << name << " scored the most points " << max << endl;
    
    return 0;
}
