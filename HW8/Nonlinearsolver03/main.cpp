//
//  main.cpp
//  Non-linear Solver3
//
//  Created by 张君陶 on 2021/11/5.
//

#include <iostream>
#include <iomanip>

#include "NonlinearSolver3.hpp"
#include "Bond.hpp"
using namespace std;

int main(){
    double F=100.0;
    double T=3.0;
    double C=1.2;
    
    Intermediary B(T,C,F);
    
    double P=98.56;
    double Acc=0.0001;
    double LEnd=0.0;
    double REnd=1.0;
    double Guess=0.2;
    
    NonlinearSolver<Intermediary> solver1(P, LEnd, REnd, Acc, Guess);
    cout << "Root of Intermediary by Bisect: " << fixed << setprecision(4)<< solver1.SolveByBisect(&B) << endl;
    cout << "Root of Intermediary by Newton-Raphson: " << fixed << setprecision(4)<< solver1.SolveByNR(&B) << endl;
    
    return 0;
}

//Root of Intermediary by Bisect: 0.0168
//Root of Intermediary by Newton-Raphson: 0.0168
//Program ended with exit code: 0
