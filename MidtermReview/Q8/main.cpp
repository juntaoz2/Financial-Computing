//
//  main.cpp
//  scratch4
//
//  Created by 张君陶 on 2021/11/7.
//

#include<iostream>
#include<stdlib.h>
#include "matrix.hpp"
using namespace std;
// Define the overloaded addition operator for Matrix
int main(){
    Matrix m1(1), m2(2), m3;
    m3 = m1 + m2; // Using overloaded addition operator for Matrix
    
    cout << "Matrix m1 is: " << endl;
    m1.Display();

    cout << "Matrix m2 is: " << endl;
    m2.Display();
    
    cout << "Matrix m1 + m2 is: " << endl;
    m3.Display();
    return 0;
}
