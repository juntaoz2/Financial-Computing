//
//  Bond.cpp
//  Non-linear Solver3
//
//  Created by 张君陶 on 2021/11/5.
//

#include <iostream>
#include <iomanip>
#include "NonlinearSolver3.hpp"
#include "Bond.hpp"
#include <cmath>


//------------------------------------------
double Bond::PriceBond(double T, double C, double F, double y){
    double P = 0;
    for (int i = 1; i <= T; i++) {
        P += C*exp(-y*i);}
    P += F*exp(-y*T);
    return P;
}

double Bond::DeriveBond(double T, double C, double F, double y){
    double P=0;
    for (int i=1; i<=T;i++){
        P += (-i)*C*exp(-y*i);}
    P += F*exp(-y*T)*(-T);
    return P;
}

//-------------------------------------------------

double Intermediary::Value(double y){
    return PriceBond(T,C,F,y);}

double Intermediary::Deriv(double y){
    return DeriveBond(T,C,F,y);}
