//
//  BinomialTreeModel02.hpp
//  Homework6
//
//  Created by 张君陶 on 2021/10/15.
//

#ifndef BinomialTreeModel02_hpp
#define BinomialTreeModel02_hpp

#include <stdio.h>

#endif /* BinomialTreeModel02_hpp */

#ifndef BinomialTreeModel02_hpp
#define BinomialTreeModel02_hpp

#include <stdio.h>

#endif /* BinomialTreeModel02_hpp */
#pragma once
//namespace fre {

#pragma once
#include<iostream>
#include <stdio.h>
class BinModel
{
private:
    double S0 = 106.00;
    double U = 1.15125;
    double D = 0.86862;
    double R = 1.00545;
public:
    //computing risk-neutral probability
    double RiskNeutProb();

    //computing the stock price at node n,i
    double S(int n, int i);

    //inputting, displaying and checking model data
    int GetInputData();
    double GetR();
    double GetS0();
    double GetU();
    double GetD();
};
