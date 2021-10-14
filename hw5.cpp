//
//  hw4.cpp
//  Homework4
//
//  Created by 张君陶 on 2021/10/5.
//

#include "hw5.hpp"
//#pragma once
#include <iostream>
#include <cmath>
#include "BinomialTreeModel02.hpp"

using namespace std;

//namespace fre {
EurOption::~EurOption() {}

//double Call::Payoff(double z) const {
//    if(z>K) {
//        return z-K;}
//    return 0.0;
//}

//double Put::Payoff(double z) const {
//    if(z<K) {
//        return K-z;}
//    return 0.0;
//}

double Butterfly::Payoff(double z) const {
    if (K1<z and z<=(K1+K2)/2) {
        return z-K1;}
    if ((K1+K2)/2 <z and z<=K2) {
        return K2-z;}
    return 0.0;}

double Strangle::Payoff(double z) const {
    if (z>K2) {
        return z-K2;}
    if (z<=K1) {
        return K1-z;}
    return 0.0;}


double OptionCalculation::PriceByCRR(const BinomialTreeModel& Model) {
    double optionPrice = 0.0;
    double q = Model.RiskNeutProb();
    int N = pOption->GetN();
    double* pPrice = new double[N + 1];
    for (int i = 0; i <= N; i++) {
        pPrice[i] = pOption->Payoff(Model.CalculateAssetPrice(N, i)); }
    for (int n = N - 1; n >= 0; n--) {
        for (int i = 0; i <= n; i++){
            pPrice[i] = (q * pPrice[i + 1] + (1 - q) * pPrice[i]) / Model.GetR();}}
    optionPrice = pPrice[0];
    delete[] pPrice;
    pPrice = nullptr;
    return optionPrice;}
