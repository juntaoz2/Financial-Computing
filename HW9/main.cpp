//
//  main.cpp
//  Homework9
//
//  Created by 张君陶 on 2021/11/4.
//

#include <iostream>
#include "hw9.hpp"
using namespace std;

int main(){
    double S0=106.0, r=0.058, sigma=0.46;
    MCModel Model(S0,r,sigma);
    double T =9.0/12.0, K=100.0;
    int m=1;
    
    EurCall call(T,K,m);
    long N=30000;
    call.PriceByMC(Model,N);
    
    cout << "European Call by direct Monte Carlo = " << call.GetPrice() << endl;
    
    EurPut put(T,K,m);

    put.PriceByMC(Model,N);
    
    cout << "European Put by direct Monte Carlo = " << put.GetPrice() << endl; return 0;
}
 
//European Call by direct Monte Carlo = 21.3803
//European Put by direct Monte Carlo = 11.3967
//Program ended with exit code: 0
