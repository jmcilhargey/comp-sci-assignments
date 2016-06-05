#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "gotoxy.h"

using namespace std;

const char PACMAN = '@';
const char BOUNDRY = '#';
const char FOOD = 'x';

class Pacman {
public:
    int x;
    int y;
    Pacman(int x = 1, int y = 1);
};

Pacman::Pacman(int x, int y) {
    x = x;
    y = y;
}

bool makeMove (int x, int y, vector<string> &gameMap, int &score, char direction, vector<Pacman> snake) {
    bool validMove = false;
    
    switch (direction) {
        case 'U': x++;
            break;
        case 'D': x--;
            break;
        case 'R': y++;
            break;
        case 'L': y--;
            break;
    }
    
    char move = gameMap.at(x).at(y);
    Pacman newSnake(x, y);
    
    switch (move) {
        case BOUNDRY :
            validMove = false;
            break;
        case FOOD :
            validMove = true;
            score++;
            snake.push_back(newSnake);
            break;
        case ' ' :
            validMove = true;
            break;
    }
    return validMove;
}

vector<string> openMap (vector<string> &gameMap) {
    fstream file;
    string line, entry;
    
    cout << "Enter the name of a map file: ";
    getline(cin, entry);
    
    file.open(entry, ios::in);
    
    if (file) {
        while (getline(file, line)) {
            gameMap.push_back(line);
        }
    }
    file.close();
    
    return gameMap;
}

void displayMap(vector<string> &gameMap) {
    
    for (string line : gameMap) {
        cout << line << endl;
    }
}



int main() {
    
    bool game_running = true;
    vector<string> ourMap;
    int score = 0;
    
    vector<Pacman> snake;
    Pacman start;
    snake.push_back(start);
    
    ourMap = openMap(ourMap);
    ourMap.at(snake.at(0).x).at(snake.at(0).y) = PACMAN;
    
    do {
        
        gotoxy(0,0);
        displayMap(ourMap);
        
        system("pause>nul");
        
        if (GetAsyncKeyState(VK_DOWN) && makeMove(snake.at(0).x, snake.at(0).y, ourMap, score, 'U', snake)) {
            
            Pacman newSnake(snake.at(0).x++, snake.at(0).y);
            snake.push_back(newSnake);
            
            ourMap.at(snake.at(0).x).at(snake.at(0).y) = ' ';
            snake.erase(snake.begin());
            
            for (Pacman link : snake) {
                ourMap.at(link.x).at(link.y) = PACMAN;
            }
    
        }
        
        if (GetAsyncKeyState(VK_UP) && makeMove(snake.at(0).x, snake.at(0).y, ourMap, score, 'D', snake)) {
            
            Pacman newSnake(snake.at(0).x--, snake.at(0).y);
            snake.push_back(newSnake);
            
            ourMap.at(snake.at(0).x).at(snake.at(0).y) = ' ';
            snake.erase(snake.begin());
            
            for (Pacman link : snake) {
                ourMap.at(link.x).at(link.y) = PACMAN;
            }
        }
        
        if (GetAsyncKeyState(VK_RIGHT) && makeMove(snake.at(0).x, snake.at(0).y, ourMap, score, 'R', snake)) {
            
            Pacman newSnake(snake.at(0).x, snake.at(0).y++);
            snake.push_back(newSnake);
            
            ourMap.at(snake.at(0).x).at(snake.at(0).y) = ' ';
            snake.erase(snake.begin());
            
            for (Pacman link : snake) {
                ourMap.at(link.x).at(link.y) = PACMAN;
            }
        }
        
        if (GetAsyncKeyState(VK_LEFT) && makeMove(snake.at(0).x, snake.at(0).y, ourMap, score, 'L', snake)) {
            
            Pacman newSnake(snake.at(0).x, snake.at(0).y--);
            snake.push_back(newSnake);
            
            ourMap.at(snake.at(0).x).at(snake.at(0).y) = ' ';
            snake.erase(snake.begin());
            
            for (Pacman link : snake) {
                ourMap.at(link.x).at(link.y) = PACMAN;
            }
        }
        
        if (GetAsyncKeyState(VK_ESCAPE)) {
            game_running = false;
        }
        
        cout << "Your score is: " << score;
        
    } while (game_running);

    return 0;
}