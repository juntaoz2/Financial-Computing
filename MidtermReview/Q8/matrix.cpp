//
//  matrix.cpp
//  scratch4
//
//  Created by 张君陶 on 2021/11/12.
//

#include "matrix.hpp"
#include <cmath>
using namespace std;

Matrix operator + (Matrix &m1, Matrix &m2) {
    Matrix m_3;
    for(int i=0;i<MAX;i++)
        for(int j=0;j<MAX;j++)
            m_3.Ma[i][j]= m1.Ma[i][j]+ m2.Ma[i][j];
    return m_3;
}
