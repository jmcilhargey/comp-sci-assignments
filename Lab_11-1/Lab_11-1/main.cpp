/***************************************************************
 Problem: Structures 11.1
 Description: This program calculates the qualities of a rectangles and determines if a square
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

struct rectangle {
    double length;
    double width;
    double area;
    double perimeter;
    bool isSquare;
};

int main() {
    
    string entry;
    rectangle r;
    
    cout << "Enter the length of a rectangle: ";
    getline(cin, entry);
    stringstream(entry) >> r.length;
    
    cout << "Enter the width of a rectangle: ";
    getline(cin, entry);
    stringstream(entry) >> r.width;
    
    if (r.length == r.width) {
        r.isSquare = true;
    }
    
    r.area = r.length * r.width;
    r.perimeter = 2 * r.length + 2 * r.width;
    
    cout << fixed << showpoint << setprecision(2);
    cout << "The area is: " << r.area << endl;
    cout << "The perimeter is: " << r.perimeter << endl;
    r.isSquare ? cout << "Rectangle is a square" << endl : cout << "Rectangle is not a square" << endl;
    
    return 0;
}
