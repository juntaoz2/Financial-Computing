//
//  this pointer.cpp
//  This Pointer
//
//  Created by 张君陶 on 2021/11/5.
//

#include "this pointer.hpp"
#include <iostream>
#include <cmath>
#include "BinomialTreeModel02.hpp"

using namespace std;
EurOption::~EurOption() {}

double Call::Payoff(double z) const {
    if(z>K) {
        return z-K;}
    return 0.0;
}

double Put::Payoff(double z) const {
    if(z<K) {
        return K-z;}
    return 0.0;
}


double EurOption::PriceByCRR(const BinomialTreeModel& Model) {
    double optionPrice = 0.0;
    double q = Model.RiskNeutProb();
    int N = GetN();
    double* pPrice = new double[N + 1];
    for (int i = 0; i <= N; i++) {
        pPrice[i] = Payoff(Model.CalculateAssetPrice(N, i)); }
    for (int n = N - 1; n >= 0; n--) {
        for (int i = 0; i <= n; i++){
            pPrice[i] = (q * pPrice[i + 1] + (1 - q) * pPrice[i]) / Model.GetR();}}
    optionPrice = pPrice[0];
    delete[] pPrice;
    pPrice = nullptr;
    return optionPrice;}
