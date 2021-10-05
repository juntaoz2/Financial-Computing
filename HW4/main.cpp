//
//  main.cpp
//  Homework4
//
//  Created by  on 2021/10/4.
//

#include <iostream>
#include <iomanip>
#include "BinomialTreeModel02.hpp"
#include "hw4.hpp"

using namespace std;


int main(){
    int N=8;
    double U = 1.15125, D = 0.86862, R = 1.00545;
    double S0 = 106.00, K = 100.00;
    double K1 = 100, K2=110;
    
    BinomialTreeModel Model(S0, U, D, R);
    
    Call call(N, K);
    OptionCalculation callCalculation(&call);
    cout << "European call = " << fixed << setprecision(2) << callCalculation.PriceByCRR(Model) << endl;
    
    Put put(N, K);
    OptionCalculation putCalculation(&put);
    cout << "European put = "<< fixed << setprecision(2) << putCalculation.PriceByCRR(Model) << endl;
    
    BullSpread BullS(N, K1, K2);
    OptionCalculation bullspreadCalculation(&BullS);
    cout << "Bull Spread = " << fixed << setprecision(2) << bullspreadCalculation.PriceByCRR(Model) << endl;
    
    BearSpread BearS(N, K1, K2);
    OptionCalculation bearspreadCalculation(&BearS);
    cout << "Bear Spread = "<< fixed << setprecision(2) << bearspreadCalculation.PriceByCRR(Model) << endl; return 0;
}
