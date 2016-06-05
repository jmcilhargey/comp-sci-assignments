//
//  main.cpp
//  Lab_13_3
//
//  Created by Joe McIlhargey on 5/26/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <string>
#include <sstream>
#include <iomanip>

using namespace std;



class Car {
private:
    int yearModel;
    string make;
    int speed;
public:
    void accelerate() {
        speed += 5;
    }
    void brake() {
        speed -= 5;
    }
    int getSpeed() {
        return speed;
    }
    Car(int , string );
};


Car::Car(int carYear, string carMake) {
    yearModel = carYear;
    make = carMake;
    speed = 0;
};

int main() {

    Car chevy(52, "corvette");

    chevy.accelerate();
    cout << chevy.getSpeed() << endl;
    chevy.accelerate();
    cout << chevy.getSpeed() << endl;
    chevy.accelerate();
    cout << chevy.getSpeed() << endl;
    chevy.accelerate();
    cout << chevy.getSpeed() << endl;
    chevy.accelerate();
    cout << chevy.getSpeed() << endl;
    
    chevy.brake();
    cout << chevy.getSpeed() << endl;
    chevy.brake();
    cout << chevy.getSpeed() << endl;
    chevy.brake();
    cout << chevy.getSpeed() << endl;
    chevy.brake();
    cout << chevy.getSpeed() << endl;
    chevy.brake();
    cout << chevy.getSpeed() << endl;
    
    return 0;
}
