//
//  main.cpp
//  scratch2
//
//  Created by 张君陶 on 2021/10/14.
//

#include <iostream>
#include "scratch2.hpp"
using namespace std;

double f(double x) { return x * x * x - x * x + 1; }
int main(){
    double a = 1.0;
    double b = 2.0;
    int N = 1000;
    
    Trapezoid defInt1(N, a, b, f);
    Simpson defInt2(N, a, b, f);
    
    DefIntCalculation dic1(&defInt1);
    DefIntCalculation dic2(&defInt2);
    cout << dic1.CalculateDefInt()<<endl;
    cout << dic2.CalculateDefInt()<<endl;
    
    return 0;
}
//ByTrapezoid: 2.41667
//BySimpson: 2.41667
//Program ended with exit code: 0
