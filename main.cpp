#include "BinomialTreeModel02.hpp"
#include "BinLattice02.hpp"
#include "HW6.hpp"
#include <iostream>
#include <iomanip>
#include <fstream>

using namespace std;
int main(){
    int N = 8;
    double U = 1.15125, D = 0.86862, R = 1.00545;
    double K = 100.00, S0 = 106.00;
    BinModel Model(S0, U, D, R);
    //if (Model.GetInputData() == 1) return 1;
    ofstream fout;
    fout.open("Results1_jz3587.txt");
    
    Call call(N, K);
    OptionCalculation callCalculation(&call);
    
    BinLattice<double> PriceTree1;
    BinLattice<double> X1;
    BinLattice<double> Y1;
    
    fout << "European call prices by PriceByCRR:"<< fixed << setprecision(3) << callCalculation.PriceByCRR(Model) << endl << endl;
    
    fout << "European call prices by HW6 PriceByCRR:"<< fixed << setprecision(3) << callCalculation.PriceByCRRHW6(Model, PriceTree1, X1, Y1)<< endl << endl;
    
    fout << "Stock positions in replicating strategy:" << endl << endl;
    
    X1.Display(fout);
    
    fout << "Money market account positions in replicating strategy:" << endl << endl;
    Y1.Display(fout);
    
    

    Put put(N, K);
    OptionCalculation putCalculation(&put);
    BinLattice<double> PriceTree2;
    BinLattice<double> X2;
    BinLattice<double> Y2;

    fout << "European put prices by PriceByCRR:"<< fixed << setprecision(3) << putCalculation.PriceByCRR(Model) << endl << endl;
    
    fout << "European put prices by HW6 PriceByCRR:"<< fixed << setprecision(3) << putCalculation.PriceByCRRHW6(Model, PriceTree2, X2, Y2)<< endl << endl;
    fout << "Stock positions in replicating strategy:" << endl << endl;
    X2.Display(fout);
    fout << "Money market account positions in replicating strategy:" << endl << endl;
    Y2.Display(fout);

    fout.close();
    return 0;
}
