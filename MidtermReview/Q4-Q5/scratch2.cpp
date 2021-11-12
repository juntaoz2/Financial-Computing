//
//  scratch2.cpp
//  scratch2
//
//  Created by 张君陶 on 2021/10/14.
//
#include "scratch2.hpp"
#include <iostream>

using namespace std;

double Trapezoid::ByTrapezoid(void){
    cout << "ByTrapezoid: ";
    double h = (b - a) / N;
    double Result = 0.5 * f(a);
    for (int n = 1; n < N; n++)
        Result += f(a + n * h);
    Result += 0.5 * f(b);
    return Result * h;
}

double Simpson::BySimpson(void){
    cout << "BySimpson: ";
    double h = (b - a) / N;
    double Result = f(a);
    for (int n = 1; n < N; n++)
        Result += 4 * f(a + n * h - 0.5 * h) + 2 * f(a + n * h);
    Result += 4 * f(b - 0.5 * h) + f(b);
    return Result * h / 6;
}

