//
//  GmtrAsianCall.cpp
//  Homework11
//
//  Created by 张君陶 on 2021/11/9.
//

#include <cmath>
#include "GmtrAsianCall.hpp"
#include "EurCall.hpp"
#include <iostream>
#include <vector>
#include <iomanip>
double GmtrAsianCall::Payoff(const SamplePath& S) const{
    double Prod=1.0;
    for (int i=0; i<m; i++)
    {
        Prod=Prod*S[i];
    }
    if (pow(Prod,1.0/m)<K) return 0.0;
    return pow(Prod,1.0/m)-K;
}

double GmtrAsianCall::PriceByBSFormula(const BSModel& Model){
    double a=exp(-Model.GetR()*T)*Model.GetS0()*exp((m+1.0)*T/(2.0*m)*(Model.GetR()+Model.GetSigma()*Model.GetSigma()*((2.0*m+1.0)/(3.0*m)-1.0)/2.0));
    double b = Model.GetSigma()*sqrt((m+1.0)*(2.0*m+1.0)/(6.0*m*m));
    EurCall G(T, K);
    Price = G.PriceByBSFormula(a,b,Model.r);
    delta = G.DeltaByBSFormula(a,b,Model.r)*a/Model.GetS0();
    return Price;
}

