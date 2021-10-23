//
//  Option.cpp
//  HW7
//
//  Created by 张君陶 on 2021/10/20.
//
#include "Option.hpp"
#include "BinModel 01.hpp"
#include "BinLattice.hpp"
#include <iostream>
#include <cmath>

using namespace std;
Option::~Option(){ cout << "Option Destructor" << endl;}

double OptionCalculation::PriceBySnell(BinModel &Model, BinLattice<double>& PriceTree, BinLattice<bool>& StoppingTree)
{
    double q = Model.RiskNeutProb();
    int N = pOption->GetN();
    PriceTree.SetN(N);
    StoppingTree.SetN(N);
    
    double ContVal=0;
    for (int i = 0; i <= N; i++) // at expiration
    {
        PriceTree.SetNode(N, i, pOption->Payoff(Model.S(N, i)));
        StoppingTree.SetNode(N, i, 1);
    }

    for (int n = N - 1; n >= 0; n--)
    {
        for (int i = 0; i <= n; i++)
        {
            ContVal = (q * PriceTree.GetNode(n + 1, i + 1) + (1 - q) * PriceTree.GetNode(n + 1, i)) / (Model.GetR());
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


double Call::Payoff(double z) const{
    if (z > K) return z - K;
    return 0.0;
}
