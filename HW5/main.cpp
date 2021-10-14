#include <iostream>
#include <iomanip>
#include "BinomialTreeModel02.hpp"
#include "hw5.hpp"

using namespace std;


int main(){
    int N=8;
    double U = 1.15125, D = 0.86862, R = 1.00545;
    double S0 = 106.00;//, K = 100.00;
    double K1 = 100, K2=110;
    
    BinomialTreeModel Model(S0, U, D, R);
    
 //   Call call(N, K);
 //   OptionCalculation callCalculation(&call);
 //   cout << "European call = " << fixed << setprecision(2) << callCalculation.PriceByCRR(Model) << endl;
    
//    Put put(N, K);
  //  OptionCalculation putCalculation(&put);
//    cout << "European put = "<< fixed << setprecision(2) << putCalculation.PriceByCRR(Model) << endl;
    
    Strangle StrangleS(N, K1, K2);
    OptionCalculation StrangleCalculation(&StrangleS);
    cout << "Strangle Spread = " << fixed << setprecision(2) << StrangleCalculation.PriceByCRR(Model) << endl;
    
    Butterfly ButterflyS(N, K1, K2);
    OptionCalculation ButterflyCalculation(&ButterflyS);
    cout << "ButterflyCalculation = "<< fixed << setprecision(2) << ButterflyCalculation.PriceByCRR(Model) << endl; return 0;
}

//Strangle Spread = 28.39
//ButterflyCalculation = 1.04
//Program ended with exit code: 0
