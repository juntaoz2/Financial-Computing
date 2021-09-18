//
//  hw1.cpp
//  Homework1
//
//  Created by 张君陶 on 2021/9/12.
//

#include <stdio.h>
#include "hw1.hpp"
#include <iostream>
#include <cmath>
using namespace std;

double RiskNeutProb(double U, double D, double R) {
   return (R-D)/(U-D);
}

double S(double S0, double U, double D, int n, int i) {
   return S0*pow(U,i)*pow(D,n-i);
}


double CallPayoff(double z, double K) {
    if (z > K) {return z - K;}
    return 0.0;}

double factorial(int n) {
    double num = 1.0;
    if (n<=0)
        return num;
    do {
        num = num *n;
        n--;
    } while (n>0);
    return num;}

double PriceByCRR(double S0, double U, double D, double R, int N, double K) {
    double q = RiskNeutProb(U, D, R);
    
    double Price=0.0;
    
    double FactorialN=factorial(N);
     
    for (int i=0; i<=N;i++) {
        Price = Price + (FactorialN/(factorial(i) * factorial(N-i)))*pow(q,i) * pow(1-q, N-i)* CallPayoff(S(S0,U,D,N,i),K)/pow(R,N);}
    return Price;
}
