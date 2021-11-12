//
//  scratch2.hpp
//  scratch2
//
//  Created by 张君陶 on 2021/10/14.
//

#ifndef scratch2_hpp
#define scratch2_hpp

#include <stdio.h>

#endif /* scratch2_hpp */

#include <iostream>

#include <iostream>
using namespace std;
class DefInt{
protected:
    int N;
    double a, b;
    double (*f)(double x);
public:
    DefInt(int N_, double a_, double b_, double (*f_)(double x)) :N(N_), a(a_), b(b_), f(f_) {}
    virtual ~DefInt() {}
    virtual double ByNumApproximation(void) = 0;
};

class Trapezoid : public DefInt{
private:
    double ByTrapezoid(void);
public:
    Trapezoid(int N_, double a_, double b_, double(*f_)(double x)) :DefInt(N_, a_, b_, f_) {}
    ~Trapezoid() {}
    double ByNumApproximation(void){ return ByTrapezoid();}
};


class Simpson : public DefInt{
private:
    double BySimpson(void);
public:
    Simpson(int N_, double a_, double b_, double (*f_)(double x)) :DefInt(N_, a_, b_, f_) {}
    ~Simpson() {}
    double ByNumApproximation(void){ return BySimpson();}
};

// Complete the implementation of a constructor and the member function CalculateDefInt () ofthe following class DefIntCalculation.
// The constructor and the member function will be used in the main function.
class DefIntCalculation {
private:
    DefInt* ptr;
public:
    DefIntCalculation(DefInt* ptr_): ptr(ptr_) {} //base class pointer pointing to derive class object
    double CalculateDefInt() {return ptr->ByNumApproximation();};
};
