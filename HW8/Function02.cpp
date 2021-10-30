//
//  Function02.cpp
//  Homework8
//
//  Created by 张君陶 on 2021/10/28.
//
#pragma once
#include "Function02.hpp"

double F1::Value(double x) { return x * x - 2; }
double F1::Deriv(double x) { return 2 * x; }
double F2::Value(double x) { return x * x - a; }
double F2::Deriv(double x) { return 2 * x; }
