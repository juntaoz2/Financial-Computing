//
//  main.cpp
//  scratch3
//
//  Created by 张君陶 on 2021/10/14.
//

#include "BinModel.hpp"
#include "Options.hpp"

#include <iostream>
#include <cmath>
using namespace std;



int main(){
    double S0 = 106.00, K = 100.00;
    double U = 0.15125, D = -0.13138, R = 0.00545;
    
    BinModel Model(S0, U, D, R);
    int N = 8;
    char name[10];
    
    memset(name, '\0', 10);
    strcpy(name, "Call");
    Call Option1(N, name);
    OptionCalculation<Call>(Option1, Model);

    
    memset(name, '\0', 10);
    strcpy(name, "Put");
    Put Option2(N, name);
    OptionCalculation<Put>(Option2, Model);
    
    memset(name, '\0', 10);
    BullSpread Option3(N, "BullSpread");
    OptionCalculation<BullSpread>(Option3, Model);

    memset(name, '\0', 10);
    BearSpread Option4(N, "BearSpread");
    OptionCalculation<BearSpread>(Option4, Model);
    return 0;
}

//1. Model and Option1 should be of different type, why use <Put> instead of <Put, BinModel>
//2. Option BearSpread Price = 4.85866
//scratch3(3408,0x1000fbe00) malloc: *** error for object 0x1059792a0: pointer being freed was not allocated
//scratch3(3408,0x1000fbe00) malloc: *** set a breakpoint in malloc_error_break to debug
//(lldb)
