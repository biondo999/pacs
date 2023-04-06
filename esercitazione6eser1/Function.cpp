//
// Created by 39389 on 18/10/2022.
//

#include "Function.h"
#include <iostream>

using namespace std;

Function::Function(const vector<double> &f) : f(f) {}

vector<double> Function::derivative() const {
    vector<double> d;

    if (f.size() > 1) {
        for (size_t i = 1; i < f.size(); i++) {
            d.push_back(f[i] * i);
        }
        return d;
    }
    d.push_back(0);
    return d;
}

double Function::eval(const double point) const {
    double r=f[0];
    double x=1;
    for(size_t i=1;i<f.size();i++){
        x=x*point;
        r=r+f[i]*x;
    }
    return r;
}

void Function::print() {
    for (size_t i = 0; i < f.size(); i++) {
        cout<<f[i]<< "  ";
    }
    cout << endl;
}