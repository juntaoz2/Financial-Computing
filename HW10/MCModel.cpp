//
//  MCModel.cpp
//  Homework10
//
//  Created by 张君陶 on 2021/11/9.
//

#include "MCModel.hpp"

#include <iostream>

#include <cmath>
const double pi=4.0*atan(1.0); double Gauss(){
    double U1 = (rand() + 1.0) / (RAND_MAX + 1.0); double U2 = (rand() + 1.0) / (RAND_MAX + 1.0); return sqrt(-2.0 * log(U1)) * cos(2.0 * pi * U2);}

void MCModel::GenerateSamplePath(double T, int m, SamplePath& S) const {
    double St = S0;
    for (int k = 0; k < m; k++) {
        S[k] = St * exp((r - sigma * sigma * 0.5) * (T / m) + sigma * sqrt(T / m) * Gauss());
        St = S[k]; }}
