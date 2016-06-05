/***************************************************************
 Problem: Structures 11.4
 Description: This program calculates the dimensions of a rectangle using nested structures
 Name: Joe McIlhargey
 NameID: 1588297
 Date: 4/18/16
 Status: Complete
 ****************************************************************/

#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>

using namespace std;

struct dimensions {
    double length;
    double width;
};

struct results {
    double area;
    double perimeter;
};

struct rectangle {
    results calc;
    dimensions sizes;
};

void calcArea(rectangle &r) {
    r.calc.area = r.sizes.length * r.sizes.width;
}

void calcPerimeter(rectangle &r) {
    r.calc.perimeter = 2 * r.sizes.length + 2 * r.sizes.width;
}

int main() {
    
    rectangle box;
    string entry;
    
    cout << "Enter the length of a rectangle: ";
    getline(cin, entry);
    stringstream(entry) >> box.sizes.length;
    
    cout << "Enter the width of a rectangle: ";
    getline(cin, entry);
    stringstream(entry) >> box.sizes.width;
    
    cout << endl;
    
    calcArea(box);
    calcPerimeter(box);
    
    cout << fixed << showpoint << setprecision(2);
    cout << "The area of the rectangle is " << box.calc.area << endl;
    cout << "The perimeter of the rectangle is " << box.calc.perimeter << endl;
    
    return 0;
}
