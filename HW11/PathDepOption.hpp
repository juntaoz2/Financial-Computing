//
//  PathDepOption.hpp
//  Homework11
//
//  Created by 张君陶 on 2021/11/9.
//

#ifndef PathDepOption_hpp
#define PathDepOption_hpp

#include <stdio.h>
#include "MCModel.hpp"

#endif /* PathDepOption_hpp */
#pragma once

class PathDepOption{
protected:
    double Price, PricingError, delta, gamma,delta1;
    int m;
    double K,T;
public:
    PathDepOption(double T_, double K_, int m_) :Price(0.0), PricingError(0.0), delta(0.0), delta1(0.0),T(T_), K(K_), m(m_) {}
    virtual ~PathDepOption() {}
    virtual double Payoff(const SamplePath& S)const=0;
    double PriceByMC(const BSModel& Model, long N, double epsilon);
    double PriceByVarRedMC(const BSModel& Model, long N, PathDepOption& CVOption,double epsilon);
    virtual double PriceByBSFormula(const BSModel& Model){return 0.0;}
    virtual double BSdelta(BSModel Model) {return 0.0;}
    double GetPrice() { return Price; }
    double GetPricingError() { return PricingError; }
    double GetDelta() { return delta; }
    double GetDelta1() {return delta1;}
};

class DifferenceOfOptions: public PathDepOption{
private:
    PathDepOption* Ptr1;
    PathDepOption* Ptr2;
public:
    DifferenceOfOptions(double T_,double K_, int m_,PathDepOption* Ptr1_,PathDepOption* Ptr2_): PathDepOption(T_, K_, m_), Ptr1(Ptr1_), Ptr2(Ptr2_){}
    double Payoff(const SamplePath& S) const{return Ptr1->Payoff(S)-Ptr2->Payoff(S);}
};

class ArthmAsianCall: public PathDepOption{
public:
    ArthmAsianCall (double T_, double K_, int m_): PathDepOption(T_, K_, m_) {}
    double Payoff(const SamplePath& S) const;
};

//
