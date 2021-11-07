// EurpeanOption.cpp
//
//	Author: Daniel Duffy
//
// (C) Datasim Component Technology BV 2003
//

#ifndef EuropeanOption_cpp
#define EuropeanOption_cpp


#include "EuropeanOption.hpp"
#include <math.h>
#include <iostream>

//////////// Gaussian functions /////////////////////////////////


double EuropeanOption::n(double x) const
{

    double A = 1.0/sqrt(2.0 * 3.1415);
    return A * exp(-x*x*0.5);

}

double EuropeanOption::N(double x) const
{ // The approximation to the cumulative normal distribution


    double a1 = 0.4361836;
    double a2 = -0.1201676;
    double a3 = 0.9372980;

    double k = 1.0/(1.0 + (0.33267 * x));
    
    if (x >= 0.0)
    {
        return 1.0 - n(x)* (a1*k + (a2*k*k) + (a3*k*k*k));
    }
    else
    {
        return 1.0 - N(-x);
    }

}


// Kernel Functions (Haug)
double EuropeanOption::CallPrice() const
{

    double tmp = sig * sqrt(T);

    double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
    double d2 = d1 - tmp;


    return (U * exp((b-r)*T) * N(d1)) - (K * exp(-r * T)* N(d2));

}

double EuropeanOption::PutPrice() const
{

    double tmp = sig * sqrt(T);

    double d1 = ( log(U/K) + (b+ (sig*sig)*0.5 ) * T )/ tmp;
    double d2 = d1 - tmp;

    return (K * exp(-r * T)* N(-d2)) - (U * exp((b-r)*T) * N(-d1));

}


/////////////////////////////////////////////////////////////////////////////////////


EuropeanOption::~EuropeanOption(){}


EuropeanOption& EuropeanOption::operator = (const EuropeanOption& option2)
{

    if (this == &option2)
        return *this;
    return *this;
}

// Functions that calculate option price and sensitivities
double EuropeanOption::Price() const
{

    if (strcmp(optType, "Call") == 0)
    {
        return CallPrice();
    }
    else
        return PutPrice();

}



// Modifier functions
void EuropeanOption::toggle()
{ // Change option type (C/P, P/C)

    if (strcmp(optType, "Call")==0)
        strcpy(optType, "Put");
    else
        strcpy(optType, "Call");
}

#endif

