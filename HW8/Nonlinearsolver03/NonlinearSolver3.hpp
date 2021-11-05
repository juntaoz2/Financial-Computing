//
//  NonlinearSolver3.hpp
//  Non-linear Solver3
//
//  Created by 张君陶 on 2021/11/5.
//

#ifndef NonlinearSolver3_hpp
#define NonlinearSolver3_hpp

#include <stdio.h>

#endif /* NonlinearSolver3_hpp */

#pragma once

#include "Bond.hpp"

template<typename Function>
class NonlinearSolver{
private:
    double P;
    double LEnd;
    double REnd;
    double Acc;
    double Guess;
public:
    NonlinearSolver() : P(0), LEnd(0), REnd(0), Acc(0), Guess(0) {}
    NonlinearSolver(double P_, double LEnd_, double REnd_, double Acc_, double Guess_): P(P_), LEnd(LEnd_), REnd(REnd_), Acc(Acc_), Guess(Guess_) {}
    ~NonlinearSolver() {}
    
    void UpdateSolver(double P_, double LEnd_, double REnd_, double Acc_, double Guess_){
    P = P_;
    LEnd = LEnd_;
    REnd = REnd_;
    Acc = Acc_;
    Guess = Guess_;}
    
    double SolveByBisect(Function* Fct){
        double left = LEnd, right = REnd, mid = (left + right) / 2;
        double y_left = Fct->Value(left) - P, y_mid = Fct->Value(mid) - P;
        while (mid - left > Acc) {
            if ((y_left > 0 && y_mid > 0) || (y_left < 0 && y_mid < 0)){
                left = mid; y_left = y_mid;}
            else right = mid;
            mid = (left + right) / 2;
            y_mid = Fct->Value(mid) - P;}
        return mid;}

    double SolveByNR(Function* Fct){
        double x_prev = Guess;
        double x_next = x_prev - (Fct->Value(x_prev) - P) / Fct->Deriv(x_prev);
        while (x_next - x_prev > Acc || x_prev - x_next > Acc){
            x_prev = x_next;
            x_next = x_prev - (Fct->Value(x_prev) - P) / Fct->Deriv(x_prev);}
        return x_next;}
};
