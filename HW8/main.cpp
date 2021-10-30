//
//  main.cpp
//  Homework8
//
//  Created by 张君陶 on 2021/10/27.
//

#include <iostream>
#include <iomanip>
#include "NonlinearSolver02.hpp"
#include "Bond.hpp"
#include "Function02.hpp"

using namespace std;

int main(){
    double F = 100.0;
    double T = 3.0;
    double C = 1.2;
    
    Intermediary B(T, C, F);
    
    double Acc = 0.0001;
    double LEnd = 0.01;
    double REnd = 1.0;
    double P = 98.56;
    double Guess = 0.2;
    
    NonlinearSolver solver(P, LEnd, REnd, Acc, Guess);
    cout << "Yield by Bisect: " << fixed << setprecision(4)<< solver.SolveByBisect(&B) << endl;
    cout << "Yield by Newton-Raphson: " << fixed << setprecision(4)<< solver.SolveByNR(&B) << endl;
    return 0;
}

//Yield by Bisect: 0.0168
//Yield by Newton-Raphson: 0.0168
//Program ended with exit code: 0
