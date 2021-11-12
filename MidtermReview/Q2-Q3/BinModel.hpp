//
//  1.hpp
//  scratch3
//
//  Created by 张君陶 on 2021/11/10.
//

#ifndef __hpp
#define __hpp

#include <stdio.h>

#endif /* __hpp */
#pragma once

#include <iostream>
#include <cmath>
#include <string.h>

using namespace std;

class BinModel{
private:
    double S0;
    double U;
    double D;
    double R;
public:
    BinModel() : S0(0), U(0), D(0), R(0) {}
    BinModel(double S0_, double U_, double D_, double R_) : S0(S0_), U(U_), D(D_), R(R_) {}
    BinModel(const BinModel & binModel) : S0(binModel.S0), U(binModel.U), D(binModel.D), R(binModel.R) {}
    ~BinModel() {}
    double GetS0() const { return S0; }
    double GetU() const { return U; }
    double GetD() const { return D; }
    double GetR() const { return R; }
    double RiskNeutProb() const;
    double CalculateAssetPrice(int n, int i) const;
    void UpdateBinModel(double S0_, double U_, double D_, double R_);
};


template<typename T>
void OptionCalculation(T Op, BinModel Mo) {
    Op.GetInputData();
    cout << "Option "<<Op.GetName()<<" Price = "<<Op.PriceByCRR(Mo)<<endl;
}
