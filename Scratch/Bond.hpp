//
//  NonlinearSolver3.hpp
//  scratch4
//
//  Created by 张君陶 on 2021/11/7.
//

#ifndef NonlinearSolver3_hpp
#define NonlinearSolver3_hpp

#include <stdio.h>

#endif /* NonlinearSolver3_hpp */

#pragma once

#include "Solver03.hpp"
#include <map>
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
using namespace std;
class Bond{
private:
    double F; //face value
    int T; //maturity time
    double yield;
    map<int, double> couponMap;
public:
    Bond(double F_, int T_, const vector<double>& C_, const vector<int>& t_):F(F_),T(T_),yield(0.0){ // Asssume vector C_ and t_ have same size
        for (unsigned int i = 0; i < C_.size(); i++)
            couponMap[t_[i]] = C_[i];}
    double BondValue();
    double BondDeriv();
    double GetF() const { return F; }
    int GetT() const { return T; }
    double GetYield() const { return yield; }
    void SetYield(double y) { yield = y; }
    map<int, double>& GetCouponMap() { return couponMap; }
};

class Intermediary{
private:
    Bond * ptr;
public:
    Intermediary(Bond* ptr_) : ptr(ptr_) {}
    double Value(double y) {
        ptr->SetYield(y);
        return ptr->BondValue();};
    double Deriv(double y){
        ptr->SetYield(y);
        return ptr->BondDeriv() ;};
};
