//
//  main.cpp
//  This Pointer
//
//  Created by 张君陶 on 2021/11/5.
//

#include <iostream>
#include <iomanip>
#include "BinomialTreeModel02.hpp"
#include "this pointer.hpp"

using namespace std;


int main(){
    int N=8;
    double U = 1.15125, D = 0.86862, R = 1.00545;
    double S0 = 106.00, K = 100.00;
    
    BinomialTreeModel Model(S0, U, D, R);
    Call c(N, K);
    Put p(N, K);
    
    cout << "European call = " << fixed << setprecision(2) << c.PriceByCRR(Model)<< endl;
    
    cout << "European put = "<< fixed << setprecision(2) << p.PriceByCRR(Model) << endl;
    
    return 0;
}
