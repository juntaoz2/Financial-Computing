//
//  Options.hpp
//  scratch3
//
//  Created by 张君陶 on 2021/11/11.
//

#ifndef Options_hpp
#define Options_hpp

#include <stdio.h>

#endif /* Options_hpp */

#include <vector>
#include "BinModel.hpp"
using namespace std;
class EurOption{
protected:
    int N;
    char* name;
public:
    EurOption(int N_, char const *name_);//parameter constructor
    virtual ~EurOption();
    virtual void GetInputData() = 0;
    virtual double Payoff(double z) = 0;
    double PriceByCRR(BinModel Model);
    char* GetName() { return name; }
};

class Call : public EurOption{
private:
    double K;
public:
    Call(int N_, char const* name_);
    ~Call() {}
    void GetInputData();
    double Payoff(double z);
};

class Put : public EurOption{
private:
    double K;
public:
    Put(int N_, char const* name_);
    ~Put() {}
    void GetInputData();
    double Payoff(double z);
};

class BullSpread : public EurOption{
private:
    double K1, K2;
public:
    BullSpread(int N_, char const* name_);
    ~BullSpread() {}
    void GetInputData();
    double Payoff(double z);
};

class BearSpread : public EurOption{
private:
    double K1, K2;
public:
    BearSpread(int N_, char const* name_);
    ~BearSpread() {};
    void GetInputData();
    double Payoff(double z);
};
