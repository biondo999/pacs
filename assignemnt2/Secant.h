//
// Created by mariano on 07/04/23.
//

#ifndef ASSIGNMENT2_SECANT_H
#define ASSIGNMENT2_SECANT_H
#include "SolverBase.h"

class Secant:public SolverBase{
private:
    ResulType  x0;
    ResulType  x1;
public:

Secant(double l,double r,const Function & g,IteratorType N,EPSILON eps,ResidualType c,double x0_,double x1_){
    if (g(l)<0 && g(r)<0) std::cerr<<"SECANT_SOLVER_ERROR: the interval extrema have the same sign"<<std::endl;
    if (g(l)>0 && g(r)>0) std::cerr<<"SECANT_SOLVER_ERROR: the interval extrema have the same sign"<<std::endl;
    a=l;
    b=r;
    f=g;
    N_MAX=N;
    epsilon=eps;
    stopping_condition=c;
    s="secant";
    x0=x0_;
    x1=x1_;
}

Secant()=default;

void solve() override;
};


#endif //ASSIGNMENT2_SECANT_H
