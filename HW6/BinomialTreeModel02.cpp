//
//  BinomialTreeModel02.cpp
//  Homework6
//
//

#include "BinomialTreeModel02.hpp"
#include <iostream>
#include <cmath>

using namespace std;

double BinModel::RiskNeutProb(){
    return (R - D) / (U - D);
}
double BinModel::S(int n, int i){
    return S0 * pow(U, i) * pow(D, n - i);
}

void BinModel::UpdateBinModel(double S0_, double U_,double D_, double R_){ S0 = S0_; U = U_; D = D_; R = R_;}


int BinModel::GetInputData(){
    // Entering data
    cout << "Enter S0: "; cin >> S0;
    cout << "Enter U: "; cin >> U;
    cout << "Enter D: "; cin >> D;
    cout << "Enter R: "; cin >> R;
    cout << endl;


    // Making sure that 0 < S0, -1<D<U, -1<R
    if (S0 <= 0.0 || U <= -1.0 || D <= -1.0 || U <= D || R <= -1.0)
    {
        cout << "Illegal data ranges" << endl;
        cout << "Terminating program" << endl;
        return 1;
    }

    // Checking for arbitrage
    if (R >= U || R <= D)
    {
        cout << "Arbitrage exists" << endl;
        cout << "Terminating program" << endl;
        return 1;
    }

    cout << "Input data checked" << endl;
    cout << "There is no arbitrage" << endl << endl;
    return 0;
}
