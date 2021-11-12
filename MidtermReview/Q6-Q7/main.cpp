//
//  main.cpp
//  scratch5
//
//  Created by 张君陶 on 2021/11/12.
//

#include "Bond.hpp"
#include "Solver03.hpp"
#include <iostream>
#include <iomanip>
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
    
    cout << setiosflags(ios::fixed) << setprecision(4);
    cout << "P = " << P << endl;
    cout << "F = " << F << endl;
    cout << "T = " << T << endl;
    cout << "Year 1 Coupon: " << MyBond.GetCouponMap()[1] << endl;
    cout << "Year 2 Coupon: " << MyBond.GetCouponMap()[2] << endl;
    cout << "Year 3 Coupon: " << MyBond.GetCouponMap()[3] << endl;
    cout<<SolveByBisect<Intermediary>(&Inter, P, LEnd, REnd, Acc)<<endl;


    //cout << MyBond << endl;
    return 0;
}
//P = 98.5600
//F = 100.0000
//T = 3
//Year 1 Coupon: 1.2000
//Year 2 Coupon: 1.2000
//Year 3 Coupon: 1.2000
//0.0168
