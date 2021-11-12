//
//  Options.cpp
//  scratch3
//
//  Created by 张君陶 on 2021/11/11.
//

#include "Options.hpp"
#include "BinModel.hpp"
#include <iostream>
#include <cmath>
#include <string.h>
using namespace std;
// Complete the implementation of constructor
EurOption::EurOption(int N_, char const *name_):N(N_){
    name = new char[strlen(name_)+1];
    strcpy(name,name_);
}

// Complete the implementation of destructor
EurOption::~EurOption(){
    if (name != NULL)
        delete[] name;
    name = NULL;
}


double EurOption::PriceByCRR(BinModel Model){
    double q = Model.RiskNeutProb();
    vector<double> Price(N + 1);
    for (int i = 0; i <= N; i++){
        Price[i] = Payoff(Model.CalculateAssetPrice(N, i));}
    for (int n = N - 1; n >= 0; n--){
        for (int i = 0; i <= n; i++)
            Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / (1 + Model.GetR());}
    return Price[0];
}

Call::Call(int N_, char const* name_):EurOption(N_, name_),K(0){}

void Call::GetInputData(){
 cout << "Enter strike price: ";
 cin >> K;
}

double Call::Payoff(double z){
    if (z > K) return z - K;
    return 0.0;
}

Put::Put(int N_, char const* name_):EurOption(N_, name_),K(0){}

void Put::GetInputData(){
    cout << "Enter strike price: ";
    cin >> K;
}

double Put::Payoff(double z){
    if (z < K) return K - z;
    return 0.0;
}

BullSpread::BullSpread(int N_, char const* name_):EurOption(N_, name_),K1(0),K2(0){}

void BullSpread::GetInputData(){
    cout << "Enter strike price 1: ";
    cin >> K1;
    cout << "Enter strike price 2: ";
    cin >> K2;
}

double BullSpread::Payoff(double z){
    if (K2 <= z)
        return K2 - K1;
    else
        if (K1 < z)
            return z - K1;
    return 0.0;
}

BearSpread::BearSpread(int N_, char const* name_):EurOption(N_, name_),K1(0),K2(0){}

void BearSpread::GetInputData(){
    cout << "Enter strike price 1: ";
    cin >> K1;
    cout << "Enter strike price 2: ";
    cin >> K2;
    cout << endl;
}

double BearSpread::Payoff(double z){
    if (K2 <= z) return 0.0;
    else if (K1 < z) return K2 - z;
    return K2 - K1;
}
