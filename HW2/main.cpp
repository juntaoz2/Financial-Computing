//
//  main.cpp
//  Homework2
//
//  Created by 张君陶 on 2021/9/18.
//
#include "hw2.hpp"
#include <iostream>
#include <iomanip>
using namespace std;
using namespace fre;

int main() {
    double S0 = 106.0, U = 1.15125, D =  0.86862, R = 1.00545;
//    if (GetInputData(S0, U, D, R) != 0)
//        return -1;
    double K = 100.0; //strike price
    int N = 8; //steps to expiry
    //cout << "Enter call option data:" << endl;
    GetInputData(N,K);
    double* optionPrice = NULL;
    cout << "European Digit Call option price = " << fixed << setprecision(2)<< *PriceByCRR(S0, U, D, R, N, K, *DigitCallPayoff) << endl;
    cout << "European Call option price = " << fixed << setprecision(2)<< *PriceByCRR(S0, U, D, R, N, K, *CallPayoff) << endl;
    
    cout << "European Digit Put option price = " << fixed << setprecision(2)<< *PriceByCRR(S0, U, D, R, N, K, *DigitPutPayoff) << endl;
    cout << "European Put option price = " << fixed << setprecision(2)<< *PriceByCRR(S0, U, D, R, N, K, PutPayoff) << endl;
    
    delete optionPrice;
    optionPrice = NULL;
    return 0;
}

//Enter steps to expiry N: 8
//Enter strike price K: 100

//European Digit Call option price = 0.58
//European Call option price = 21.68
//European Digit Put option price = 0.38
//European Put option price = 11.43
//Program ended with exit code: 0








