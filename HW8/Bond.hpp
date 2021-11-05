//
//  Bond.hpp
//  Non-linear Solver3
//
//  Created by 张君陶 on 2021/11/5.
//

#ifndef Bond_hpp
#define Bond_hpp

#include <stdio.h>

#endif /* Bond_hpp */

#ifndef Bond_hpp
#define Bond_hpp

#include <stdio.h>

#endif /* Bond_hpp */

#pragma once
#include "NonlinearSolver3.hpp"

class Function{
public:
    virtual double Value(double x) = 0;
    virtual double Deriv(double x) = 0;
    virtual ~Function() {}
};
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
