//
//  BSModel.hpp
//  HW7
//
//
#ifndef BSModel_h

#include <cmath>
#include "BinModel 01.hpp"

using namespace std;

class BSModel {
private:
    double S0, r, sigma;
public:
    BSModel(double S0_, double r_, double sigma_) {
        S0 = S0_; r = r_; sigma = sigma_;
    }
    BinModel ApproxBinModel(double h) {
        double U = exp(sigma * sqrt(h));
        double D = exp(-sigma * sqrt(h));
        double R = exp(r * h);
        BinModel ApproxModel(S0, U, D, R);
        return ApproxModel;
    }
};

#endif // !BSModel_h
