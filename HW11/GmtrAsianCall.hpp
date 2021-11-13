//
//  GmtrAsianCall.hpp
//  Homework11
//
//  Created by 张君陶 on 2021/11/9.
//

#ifndef GmtrAsianCall_hpp
#define GmtrAsianCall_hpp

#include <stdio.h>

#endif /* GmtrAsianCall_hpp */
#pragma once
#include "PathDepOption.hpp"


class GmtrAsianCall: public PathDepOption{
public:
    GmtrAsianCall(double T_, double K_, int m_): PathDepOption(T_, K_, m_){}
    double Payoff(const SamplePath& S) const;
    double PriceByBSFormula(const BSModel& Model);
};
