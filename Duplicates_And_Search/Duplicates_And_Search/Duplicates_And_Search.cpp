//
//  main.cpp
//  Duplicates_And_Search
//
//  Created by Joe McIlhargey on 5/18/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <fstream>

using namespace std;

struct Number {
    int value;
    int count = 1;
};

void readFile(vector<Number> &numList) {

    fstream file;
    string line;
    Number tempNum;
    
    file.open("integers.txt", ios::in);
    
    if (file) {
    
        while(getline(file, line)) {
            
            stringstream(line) >> tempNum.value;
            
            long startIndex = 0;
            long endIndex = numList.size() - 1;
            long midIndex = (startIndex + endIndex) / 2;
            bool valInsert = false;

            while (startIndex < endIndex - 1 && !valInsert) {
                
                midIndex = (startIndex + endIndex) / 2;
            
                if (numList.at(midIndex).value > tempNum.value) {
                    endIndex = midIndex;
                } else if (numList.at(midIndex).value < tempNum.value) {
                    startIndex = midIndex;
                } else {
                    numList.at(midIndex).count++;
                    valInsert = true;
                }
            }
            if (!valInsert) {
                numList.insert(numList.begin() + midIndex, tempNum);
            }
            
        }
        file.close();
        
    } else {
        cout << "Error opening file" << endl;
    }
}

void readVector(vector<Number> &numList) {
    
   for (Number num : numList) {
       cout << num.value << "\t" << num.count << endl;
   }
    
}

int main() {
    
    vector<Number> numList;
    vector<string> data;
    
    readFile(numList);
    
    readVector(numList);
    
    
    return 0;
}
