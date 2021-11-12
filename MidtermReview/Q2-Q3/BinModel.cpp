//
//  1.cpp
//  scratch3
//
//  Created by 张君陶 on 2021/11/10.
//

#include "BinModel.hpp"
#include <cmath>
double BinModel::RiskNeutProb() const{
    return (R-D)/(U-D);}

double BinModel::CalculateAssetPrice(int n, int i) const{
    return S0*pow(1+U, i)*pow(1+D, n-i);}

void BinModel::UpdateBinModel(double S0_, double U_, double D_, double R_){
    S0 = S0_;
    U = U_;
    D = D_;
    R = R_;
}
