// TestEuropeanOption.cpp
// Test program for the exact solutions of European options.
// (C) Datasim Component Technology BV 2003-2006
//

#include "EuropeanOption.hpp"
#include <iostream>
#include <math.h>
#include <string.h>
int main()
{
    double U = 50;
    double sig = 0.3;
    double K = 50;
    double r = 0.1;
    double T = 3.0/12.0;
    double b=0.1;
    char *optType = new char[5];
    strcpy(optType, "Put");
    
    EuropeanOption put1(r,sig,K,T,U,b,optType);
	// Call option on a stock
    //	EuropeanOption callOption;
	cout << "Put option on a stock: " << put1.Price() << endl;
    
    double q = 1.5;
    double PV_q = q*exp(-0.1*2/12);
    double U2 = U-PV_q;
    EuropeanOption put2(r,sig,K,T,U2,b,optType);
    cout << "Put option on a stock: " << put2.Price() << endl;
    cout << "difference:"<<put1.Price()-put2.Price()<<endl;
//	cout << "Delta on a call option: " << callOption.Delta() << endl;

	// Put option on a stock index
//	EuropeanOption indexOption;
//	indexOption.optType = "P";
//	indexOption.U = 100.0;
//	indexOption.K = 95.0;
//	indexOption.T = 0.5;
//	indexOption.r = 0.10;
//	indexOption.sig = 0.20;

//	double q = 0.05;		// Dividend yield
//	indexOption.b = indexOption.r - q;

//	cout << "Put option on an index: " << indexOption.Price() << endl;
//	cout << "Delta on a put option: " << indexOption.Delta() << endl;

	return 0;
}

