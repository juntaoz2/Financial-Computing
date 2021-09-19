//
//  hw2.hpp
//  Homework2
//
//  Created by 张君陶 on 2021/9/18.
//

#ifndef hw2_hpp
#define hw2_hpp

#include <stdio.h>

#endif /* hw2_hpp */


#include <iostream>
#include <cmath>
using namespace std;
namespace fre {
//inputting and displaying option data
int GetInputData(int& N, double& K);
//pricing European option
double * PriceByCRR(double S0, double U, double D, double R, int N, double K, double (*Payoff)(double z, double K));
//computing Call Payoff
double CallPayoff(double z, double K);
//computing Put Payoff
double PutPayoff(double z, double K);

double CalculateAssetPrice(double S0, double U, double D, int n, int i);

double DigitCallPayoff(double z, double K);
double DigitPutPayoff(double z, double K);

}
