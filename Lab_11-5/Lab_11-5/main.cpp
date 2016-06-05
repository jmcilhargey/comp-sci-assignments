/***************************************************************
 Problem: Structures 11.5
 Description: This program calculates airline data for a year
 Name: Joe McIlhargey
 NameID: 1588297
 Date: 4/18/16
 Status: Complete
 ****************************************************************/

#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>

using namespace std;

struct airport {
    int totalPlanesLanded;
    int totalPlanesDeparted;
    int maxLandedInMonth;
    int minLandedInMonth;
};

int main() {
    
    const int MONTHS = 3;
    airport yearlyTraffic[MONTHS];
    string entry;
    
    for (int i = 0; i < MONTHS; i++) {
        
        cout << "Enter the total planes landed: ";
        getline(cin, entry);
        stringstream(entry) >> yearlyTraffic[i].totalPlanesLanded;
        
        cout << "Enter the total planes departed: ";
        getline(cin, entry);
        stringstream(entry) >> yearlyTraffic[i].totalPlanesDeparted;
        
        cout << "Enter the greatest landed for day in month #" << i + 1 << " : ";
        getline(cin, entry);
        stringstream(entry) >> yearlyTraffic[i].maxLandedInMonth;
        
        cout << "Enter the least landed for day in month #" << i + 1 << " : ";
        getline(cin, entry);
        stringstream(entry) >> yearlyTraffic[i].minLandedInMonth;
        
    }

    int totalLanded = 0;
    int totalDeparted = 0;
    double averageLanded;
    double averageDeparted;
    int maxLanded = yearlyTraffic[0].maxLandedInMonth;
    int maxLandedMonth = 1;
    int minLanded = yearlyTraffic[0].minLandedInMonth;
    int minLandedMonth = 1;
    
    for (int j = 0; j < MONTHS; j++) {
        
        totalLanded += yearlyTraffic[j].totalPlanesLanded;
        totalDeparted += yearlyTraffic[j].totalPlanesDeparted;
        if (maxLanded < yearlyTraffic[j].maxLandedInMonth) {
            maxLanded = yearlyTraffic[j].maxLandedInMonth;
            maxLandedMonth = j + 1;
        }
        if (minLanded > yearlyTraffic[j].minLandedInMonth) {
            minLanded = yearlyTraffic[j].minLandedInMonth;
            minLandedMonth = j + 1;
        }
    }
    
    averageLanded = static_cast<double>(totalLanded) / MONTHS;
    averageDeparted = static_cast<double>(totalDeparted) / MONTHS;
    
    cout << "The total planes landed in the year is: " << totalLanded << endl;
    cout << "The total planes departed in the year is: " << totalDeparted << endl;
    cout << "The average landed per month is: " << averageLanded << endl;
    cout << "The average departed per month is: " << averageDeparted << endl;
    cout << "The max landed is: " << maxLanded << " during month #" << maxLandedMonth << endl;
    cout << "The min landed is: " << minLanded << " during month #" << minLandedMonth << endl;
    
    return 0;
}
