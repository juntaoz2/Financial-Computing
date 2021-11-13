//
//  EurCall.hpp
//  Homework11
//
//  Created by 张君陶 on 2021/11/9.
//

#ifndef EurCall_hpp
#define EurCall_hpp

#include <stdio.h>

#endif /* EurCall_hpp */

#pragma once
class EurCall
{
private:
    double T,K;
    double d_plus(double S0, double sigma, double r);
    double d_minus(double S0, double sigma, double r);
public:
    EurCall(double T_, double K_): T(T_), K(K_) {}
    double N(double x);
    double PriceByBSFormula(double S0, double sigma, double r);
    double VegaByBSFormula(double S0, double sigma, double r);
    double DeltaByBSFormula(double S0, double sigma, double r);
};
