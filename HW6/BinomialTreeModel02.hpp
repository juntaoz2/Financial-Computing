//
//  BinomialTreeModel02.hpp
//  Homework6
//


#ifndef BinomialTreeModel02_hpp
#define BinomialTreeModel02_hpp

#include <stdio.h>

#endif /* BinomialTreeModel02_hpp */
#pragma once
//namespace fre {

#pragma once
#include<iostream>
#include <stdio.h>
class BinModel
{
private:
    double S0 ;
    double U;
    double D;
    double R;
public:
    BinModel() :S0(0), U(0), D(0), R(0) {}
    BinModel(double S0_, double U_, double D_, double R_)
    :S0(S0_), U(U_), D(D_), R(R_) {}
    BinModel(const BinModel& B):S0(B.S0), U(B.U), D(B.D), R(B.R) {}
    ~BinModel() {}
    //computing risk-neutral probability
    double RiskNeutProb();
    //computing the stock price at node n,i
    double S(int n, int i);
    
    void UpdateBinModel(double S0_, double U_,double D_, double R_);
    //inputting, displaying and checking model data
    int GetInputData();
    double GetS0() const { return S0; }
    double GetU() const { return U; }
    double GetD() const { return D; }
    double GetR() const { return R; }
};
