//
//  NonlinearSolver02.hpp
//  Homework8
//
//  Created by on 2021/10/27.
//
#pragma once
#ifndef NonlinearSolver02_hpp
#define NonlinearSolver02_hpp

#include <stdio.h>
#include "Bond.hpp"
#include "Function02.hpp"

#endif /* NonlinearSolver02_hpp */

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
    double SolveByBisect(Function *Fct);
    double SolveByNR(Function *Fct);
};
