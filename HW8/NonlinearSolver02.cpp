//
//  NonlinearSolver02.cpp
//  Homework8
//
//  Created by on 2021/10/27.
//
#pragma once
#include "NonlinearSolver02.hpp"
#include "Bond.hpp"
#include "Function02.hpp"


double NonlinearSolver::SolveByBisect(Function* Fct) {
    double left = LEnd, right = REnd, mid = (left + right) / 2;
    double y_left = Fct->Value(left) - P, y_mid = Fct->Value(mid) - P;
    while (mid - left > Acc){
        if ((y_left > 0 && y_mid > 0) || (y_left < 0 && y_mid < 0)){
            left = mid; y_left = y_mid;}
        else right = mid;
        mid = (left + right) / 2;
        y_mid = Fct->Value(mid) - P;}
    return mid;}

double NonlinearSolver::SolveByNR(Function* Fct){
    double x_prev = Guess;
    double x_next = x_prev - (Fct->Value(x_prev) - P) / Fct->Deriv(x_prev);
    while (x_next - x_prev > Acc || x_prev - x_next > Acc){
        x_prev = x_next;
        x_next = x_prev - (Fct->Value(x_prev) - P) / Fct->Deriv(x_prev);}
    return x_next;}
