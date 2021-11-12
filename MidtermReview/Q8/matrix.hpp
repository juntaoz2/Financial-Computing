//
//  matrix.hpp
//  scratch4
//
//  Created by 张君陶 on 2021/11/12.
//

#ifndef matrix_hpp
#define matrix_hpp

#include <stdlib.h>
#pragma once
#include <iostream>
#define MAX 3
using namespace std;
#endif /* matrix_hpp */
class Matrix{
private:
    int Ma[MAX][MAX];
public:
    Matrix() {
        for(int i=0;i<MAX;i++)
            for(int j=0;j<MAX;j++)
                Ma[i][j]=0; }
    Matrix(int a) {
        for(int i=0;i<MAX;i++)
            for(int j=0;j<MAX;j++)
                Ma[i][j]=a++; }
    ~Matrix() { }
    void Display() {
        for(int i=0;i<MAX;i++){
            for(int j=0;j<MAX;j++)
                cout << Ma[i][j] << " ";
            cout << endl;}
        cout << endl; }
 // Declare a friend function for overloading the addition operator for Matrix
    friend Matrix operator + (Matrix &m1, Matrix &m2);
};
