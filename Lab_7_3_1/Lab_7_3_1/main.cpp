//
//  main.cpp
//  Lab_7_3_1
//
//  Created by Joe McIlhargey on 4/11/16.
//  Copyright © 2016 Joe McIlhargey. All rights reserved.
//

#include <iostream>
#include <vector>

using namespace std;

void f(vector<int> gv) {
    
    vector<int> lv(10);
    lv = gv;
    for (int val : lv) {
        cout << val << endl;
    }
    
    vector<int> lv2(gv);
    for (int val : lv2) {
        cout << val << endl;
    }
}

// Uses overloading for function call with 2 arguments
void f(vector<int> v1, vector<int> v2) {
    for (int i = 0; i < v1.size(); i++) {
        v1[i] += v2[i];
    }
}

int main() {
    
    vector<int> gv = { 1, 2, 4, 8, 16, 32, 64, 128, 256, 512 };
    
    f(gv);
    
    vector<int> vv;
    int factorial = 1;
    for (int i = 1; i <= 10; i++) {
        vv.push_back(factorial * i);
        factorial *= i;
    }
    
    f(vv);
    
    f(gv, gv);
    
    return 0;
}
