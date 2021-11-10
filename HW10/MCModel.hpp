//
//  MCModel.hpp
//  Homework10
//
//  Created by 张君陶 on 2021/11/9.
//

#ifndef MCModel_hpp
#define MCModel_hpp

#include <stdio.h>

#endif /* MCModel_hpp */

#pragma once
#include <vector>
#include <cstdlib>
#include <ctime>
using namespace std;

typedef vector<double> SamplePath;

class MCModel {
private:
    double S0, r, sigma;
public:
    MCModel() :S0(0.0), r(0.0), sigma(0.0) {}
    MCModel(double S0_, double r_, double sigma_) :S0(S0_), r(r_), sigma(sigma_) {
        srand((unsigned)time(NULL));}
    void GenerateSamplePath(double T, int m, SamplePath& S) const;
    double GetS0() const { return S0; }
    double GetR() const { return r; }
    double GetSigma() const { return sigma; }
    void SetS0(double S0_) { S0 = S0_; }
    void SetR(double r_) { r = r_; }
    void SetSigma(double sigma_) { sigma = sigma_; }
};
