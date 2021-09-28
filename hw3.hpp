//
//  hw3.hpp
//  Homework3
//
//  Created by 张君陶 on 2021/9/26.
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
    ~Deflnt();
    double ByTrapzoid(int N);
    double BySimpson();
};


