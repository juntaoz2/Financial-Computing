//
//  hw9.hpp
//  Homework9
//
//  Created by 张君陶 on 2021/11/4.
//

#ifndef hw9_hpp
#define hw9_hpp

#include <stdio.h>
#include <iostream>
#endif /* hw9_hpp */
#pragma once
#include "MCModel.hpp"
#include <cmath>

class PathDepOption{
protected:
    double Price;
    int m;
    double K;
    double T;
public:
    PathDepOption(double T_, double K_, int m_) :Price(0.0), T(T_), K(K_), m(m_) {}
    virtual ~PathDepOption() {};
    virtual double Payoff(const SamplePath& S) const = 0;
    double PriceByMC(const MCModel& Model, long N);
    double GetT() { return T; }
    double GetPrice() { return Price; }
};

class EurCall : public PathDepOption{
public:
    EurCall(double T_, double K_, int m_) :PathDepOption(T_, K_,m_) {}
    double Payoff(const SamplePath& S) const;
};

class EurPut : public PathDepOption{
public:
    EurPut(double T_, double K_, int m_) :PathDepOption(T_, K_, m_) {}
    double Payoff(const SamplePath& S) const;
};
