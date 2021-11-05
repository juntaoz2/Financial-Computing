//
//  this pointer.hpp
//  This Pointer
//
//  Created by 张君陶 on 2021/11/5.
//

#ifndef this_pointer_hpp
#define this_pointer_hpp

#include <stdio.h>

#endif /* this_pointer_hpp */
#pragma once
#include "BinomialTreeModel02.hpp"

class EurOption {
private:
    EurOption() :N(0) {}
    EurOption(const EurOption& option) : N(option.N) {}
protected:
    int N;
public:
    EurOption(int N_) : N(N_) {}
    int GetN() const { return N; }
    virtual double Payoff(double z) const = 0;
    double PriceByCRR(const BinomialTreeModel& model);
    virtual ~EurOption() = 0;
};


class Call :public EurOption {
private:
    double K;
public:
    Call(int N_, double K_) : EurOption(N_), K(K_) {}
    ~Call() {}
    double Payoff(double z) const;};

class Put :public EurOption {
private:
    double K;
public:
    Put(int N_, double K_) : EurOption(N_) , K(K_) {}
    ~Put() {}
    double Payoff(double z) const;
};

double PriceByCRR(const BinomialTreeModel& model, const EurOption& pOption);

