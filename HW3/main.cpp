//
//  main.cpp
//  Homework3
//
//  Created by on 2021/9/26.
//

#include <iostream>
#include "hw3.hpp"
#include <cmath>
using namespace std;

int main() {
    double a=1.0;
    double b=2.0;
    Deflnt MyInt(a, b, *f);
    int N;
    GetInputData(N);
    
    cout<<"Integral By Trapezoidal approximation: " << MyInt.ByTrapzoid(N)<<endl;
    cout<<"Integral By Simpson: " << MyInt.BySimpson()<<endl;
    return 0;
}

//Please enter an integer N: 100

//Integral By Trapezoidal approximation: 2.41673
//Integral By Simpson: 2.41667
//Program ended with exit code: 0
