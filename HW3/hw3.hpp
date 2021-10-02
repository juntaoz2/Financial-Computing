//
//  hw3.hpp
//  Homework3
//
//  Created by on 2021/9/26.
//

#ifndef hw3_hpp
#define hw3_hpp

#include <stdio.h>

#endif /* hw3_hpp */

#include <iostream>
#include <cmath>
using namespace std;

double f(double x);
int GetInputData(int&N);

class Deflnt {
private:
    double a;
    double b;
    double (*f) (double x);
    
public:
    Deflnt();
    Deflnt(double aa, double bb, double (*function)(double x));
    Deflnt(const Deflnt& d);
    ~Deflnt(); //here i do not define the destructor in the C++ file because i dont have dynamic allocated memory or pointer in class. When a class contains a pointer to memory allocated in class, we should write a destructor to release memory before the class instance is destroyed. This must be done to avoid memory leak.
    double ByTrapzoid(int N);
    double BySimpson();
};


