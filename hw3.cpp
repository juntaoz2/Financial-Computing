//
//  hw3.cpp
//  Homework3
//
//  Created by 张君陶 on 2021/9/26.
//

#include "hw3.hpp"
#include <stdio.h>
#include <iostream>
#include <cmath>
using namespace std;
double f(double x){
    return x*x*x-x*x+1;}

int GetInputData(int& N) {cout <<"Please enter an integer N: "; cin >> N;
    cout<< endl;
    return 0;
}

Deflnt::Deflnt(double aa, double bb, double (*function)(double x) ){
    a = aa;
    b = bb;
    f = function;
}

Deflnt::Deflnt(const Deflnt& d ) {
    a = d.a;
    b = d.b;
    f = d.f;
}

Deflnt::~Deflnt() {
    if (a!=0) {
        a=0; }
    if (b!=0) {
        b=0; }
}

double Deflnt::ByTrapzoid(int N) {
    double h = (b-a)/N;
    double summation = f(a);
    for (int i = 1; i<N; i++) {
        summation += 2*f(a+i*h);
    }
    summation += f(b);
    return summation*h/2;
}

double Deflnt::BySimpson() {
    return (f(a)+4*f((a+b)/2)+f(b))*(b-a)/6;}

