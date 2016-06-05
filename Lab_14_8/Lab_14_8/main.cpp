//
//  main.cpp
//  Lab_14_8
//
//  Created by Joe McIlhargey on 5/26/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>

using namespace std;

class Circle {
private:
    double radius;
    double pi = 3.14159;
public:
    Circle();
    Circle(double );
    void setRadius(double );
    double getRadius();
    double getArea();
    double getDiameter();
    double getCircumference();
};

Circle::Circle() {
    radius = 0;
}

Circle::Circle(double rad) {
    radius = rad;
}

void Circle::setRadius(double rad) {
    radius = rad;
}

double Circle::getRadius() {
    return radius;
}

double Circle::getArea() {
    return pi * pow(radius, 2);
}

double Circle::getDiameter() {
    return radius * 2;
}

double Circle::getCircumference() {
    return 2 * pi * radius;
}

int main() {
    
    string entry;
    double radius;
    
    cout << "Enter the radius of a circle to calculate values: ";
    getline(cin, entry);
    stringstream(entry) >> radius;
    
    Circle circle(radius);
    
    cout << "Circle area is: " << circle.getArea() << endl;
    cout << "Circle diameter is: " << circle.getDiameter() << endl;
    cout << "Circle circumference is: " << circle.getCircumference() << endl;
    
    
    return 0;
}
