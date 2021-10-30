//
//  Bond.hpp
//  Homework8
//
//  Created by 张君陶 on 2021/10/27.
//
#pragma once
#ifndef Bond_hpp
#define Bond_hpp

#include <stdio.h>

#endif /* Bond_hpp */

#include "NonlinearSolver02.hpp"
#include "Function02.hpp"
//---------------------------------
class Bond{
public:
    double T, C, F;
    Bond(double T_, double C_, double F_) :T(T_), C(C_), F(F_) { }
    double PriceBond(double T, double C, double F, double y);
    double DeriveBond(double T, double C, double F, double y);
};
//--------------------------
class Intermediary : public Bond, public Function{
public:
    Intermediary(double T_, double C_, double F_): Bond(T_, C_, F_) { }
    double Value(double y);
    double Deriv(double y);
};
