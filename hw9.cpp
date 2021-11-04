//
//  hw9.cpp
//  Homework9
//
//  Created by 张君陶 on 2021/11/4.
//

#include <iostream>
#include "hw9.hpp"
#include <cmath>

double PathDepOption::PriceByMC(const MCModel& Model, long N){
    double H = 0.0, Hsq = 0.0, Heps = 0.0; SamplePath S(m);
    for (long i = 0; i < N; i++){
        Model.GenerateSamplePath(T, m, S);
        H = (i * H + Payoff(S)) / (i + 1.0); }
    Price = exp(-Model.GetR() * T) * H;
    return Price; }

double EurCall::Payoff(const SamplePath& S) const {
    if (S[0] > K)
        return S[0]-K;
    return 0.0;}

double EurPut::Payoff(const SamplePath& S) const {
    if (S[0] < K)
        return K-S[0];
    return 0.0;}

