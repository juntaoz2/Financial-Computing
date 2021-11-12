//
//  main.cpp
//  scratch4
//
//  Created by 张君陶 on 2021/11/7.
//

#include <iostream>
#include <map>
#include <vector>
#include <cmath>
#include <iomanip>
#include "Bond.hpp"
#include "Solver03.hpp"
using namespace std;
int main(){
    double F=100.0; //face value
    int T=3; //maturity time
    
    vector<double> C; //coupons
    C.push_back(1.2);
    C.push_back(1.2);
    C.push_back(1.2);
    vector<int> t; //coupon times
    
    t.push_back(1); t.push_back(2); t.push_back(3);
    Bond MyBond(F,T,C,t);
    double P=98.56;
    double Acc=0.0001;
    double y;
    double LEnd = 0.0;
    double REnd = 1.0;
   // double Tgt = P;
    
    Intermediary Inter(&MyBond);
    
    SolveByBisect<Intermediary>(&Inter,double P, double LEnd, double REnd, double Acc);

    cout << setiosflags(ios::fixed) << setprecision(4);
    cout << "P = " << P << endl;
    //cout << MyBond << endl;
    return 0;
}
