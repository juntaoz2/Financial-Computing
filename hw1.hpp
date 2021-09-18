//
//  hw1.hpp
//  Homework1
//
//  Created by 张君陶 on 2021/9/12.
//

//#include "BinomialTreeModel.h"
#include <iostream>
#include <cmath>
using namespace std;

double RiskNeutProb(double U, double D, double R);
double S(double S0, double U, double D, int n, int i);

double CallPayoff(double z, double K);
double factorial(int n);
double PriceByCRR(double S0, double U, double D, double R, int N, double K);




