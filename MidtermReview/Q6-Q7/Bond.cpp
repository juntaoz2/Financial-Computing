//
//  Bond.cpp
//  scratch5
//
//  Created by 张君陶 on 2021/11/12.
//

#include "Bond.hpp"
#include <map>
#include <vector>
#include <cmath>
#include <iostream>
#include <iomanip>
#include "Solver03.hpp"

double Bond::BondValue(){
    double P = 0;
    for (int i=0;i< couponMap.size(); i++) {
        P += couponMap[i]*exp(-yield*(i));
    }
    P += F*exp(-yield*T);
    return P;
}
double Bond::BondDeriv(){
    double D = 0;
    for (int i=1;i< couponMap.size(); i++) {
        D += -couponMap[i]*i*exp(-yield*(i));
    }
    D += -F*T*exp(-yield*T);
    return D;
}
