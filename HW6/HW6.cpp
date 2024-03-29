//
//  HW6.cpp
//  Homework6
//
//  Created by 张君陶 on 2021/10/15.
//
#include "HW6.hpp"
#include "BinomialTreeModel02.hpp"
#include "BinLattice02.hpp"
#include <iostream>
#include <cmath>

using namespace std;

Option::~Option(){ cout << "Option Destructor" << endl;}

double OptionCalculation::PriceByCRR(BinModel &Model){
    double q = Model.RiskNeutProb();
    int N = pOption->GetN();
    vector<double> Price(N + 1);
    for (int i = 0; i <= N; i++)
        Price[i] = pOption->Payoff(Model.S(N, i));
    for (int n = N - 1; n >= 0; n--) {
        for (int i = 0; i <= n; i++)
            Price[i] = (q * Price[i + 1] + (1 - q) * Price[i]) / (Model.GetR());
    }
    return Price[0];
}
double OptionCalculation::PriceByCRRHW6(BinModel &Model, BinLattice<double>& PriceTree, BinLattice<double>& X, BinLattice<double>& Y){
    double q = Model.RiskNeutProb();
    int N = pOption->GetN();
    PriceTree.SetN(N);
    X.SetN(N);
    Y.SetN(N);
    double OptionValue;
    double XNode, YNode;
    for (int i = 0; i <= N; i++) {
        PriceTree.SetNode(N, i, pOption->Payoff(Model.S(N, i)));
        X.SetNode(N, i, 0);
        Y.SetNode(N, i, 0);
    }
    for (int n = N - 1; n >= 0; n--) {
        for (int i = 0; i <= n; i++) {
            XNode = (PriceTree.GetNode(n + 1, i + 1) - PriceTree.GetNode(n + 1, i)) / (Model.S(n + 1, i + 1) - Model.S(n + 1, i));
            YNode = (PriceTree.GetNode(n + 1, i) - XNode * Model.S(n + 1, i)) / (pow(Model.GetR(), 1+n));
        
            X.SetNode(n, i, XNode);
            Y.SetNode(n, i, YNode);

            OptionValue = (q * PriceTree.GetNode(n + 1, i + 1) + (1 - q) * PriceTree.GetNode(n + 1, i)) / (Model.GetR());
            PriceTree.SetNode(n, i, OptionValue);
        
        }
    }
    return PriceTree.GetNode(0, 0);
}



double OptionCalculation::PriceBySnell(BinModel &Model, BinLattice<double>& PriceTree, BinLattice<bool>& StoppingTree)
{
    double q = Model.RiskNeutProb();
    int N = pOption->GetN();
    PriceTree.SetN(N);
    StoppingTree.SetN(N);
    
    double ContVal;
    for (int i = 0; i <= N; i++) // at expiration
    {
        PriceTree.SetNode(N, i, pOption->Payoff(Model.S(N, i)));
        StoppingTree.SetNode(N, i, 1);
    }

    for (int n = N - 1; n >= 0; n--)
    {
        for (int i = 0; i <= n; i++)
        {
            ContVal = (q * PriceTree.GetNode(n + 1, i + 1) + (1 - q) * PriceTree.GetNode(n + 1, i)) / (1 + Model.GetR());
            PriceTree.SetNode(n, i, pOption->Payoff(Model.S(n, i)));
            StoppingTree.SetNode(n, i, 1);
            if (ContVal > PriceTree.GetNode(n, i))
            {
                PriceTree.SetNode(n, i, ContVal); // updated to calculated value
                StoppingTree.SetNode(n, i, 0); // set not eligible for early exercise
            }
            else if (PriceTree.GetNode(n, i) == 0.0)
            {
                StoppingTree.SetNode(n, i, 0);
            }
        }
    }
    return PriceTree.GetNode(0, 0);
}

double Put::Payoff(double z) const{
    if (z < K) return K - z;
    return 0.0;}

double Call::Payoff(double z) const{
    if (z > K) return z - K;
    return 0.0;
}
