//
//  main.cpp
//  Homework11
//
//  Created by 张君陶 on 2021/11/9.
//

#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
#include "PathDepOption.hpp"
#include "GmtrAsianCall.hpp"

using namespace std;

int main()
{
    double S0=100.0, r=0.03, sigma=0.2;
    BSModel Model(S0,r,sigma);
    
    double T =1.0/12.0, K=100.0;
    int m=30;
    
    ArthmAsianCall Option(T,K,m);
    GmtrAsianCall  CVOption(T,K,m);
    
    long N=30000;
    double epsilon =0.001;
    Option.PriceByVarRedMC(Model,N,CVOption,epsilon);
    cout<< "Arithmetic call price = " << Option.GetPrice() << endl
    << "Error = " << Option.GetPricingError() << endl
    << "delta1 = " << Option.GetDelta1() << endl<< endl;
    
    Option.PriceByMC(Model,N,epsilon);
    cout << "Price by direct MC = " << Option.GetPrice() << endl
    << "Error = " << Option.GetPricingError() << endl
    << "delta = " << Option.GetDelta() << endl;

    return 0;
}

//Arithmetic call price = 1.42608
//Error = 0.000137812
//delta1 = 0.519942

//Price by direct MC = 1.41643
//Error = 0.0119657
//delta = 0.525115
//Program ended with exit code: 0
