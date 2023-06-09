//
// Created by mariano on 07/04/23.
//

#ifndef ASSIGNMENT2_BISECTION_H
#define ASSIGNMENT2_BISECTION_H

#include "SolverBase.h"
class Bisection: public SolverBase{
public:
/*
    Bisection(double l,double r,const Function & g,IteratorType N,EPSILON eps,ResidualType c){
        if (g(l)<0 && g(r)<0) std::cerr<<"BISECTION_SOLVER_ERROR: the interval extrema have the same sign"<<std::endl;
        if (g(l)>0 && g(r)>0) std::cerr<<"BISECTION_SOLVER_ERROR: the interval extrema have the same sign"<<std::endl;
        a=l;
        b=r;
        f=g;
        N_MAX=N;
        epsilon=eps;
        stopping_condition=c;
        s="bisection";
    }
    */

    Bisection()=default;

    void read_parameters(std::string const &filename) override;


    void solve() override;


};


#endif //ASSIGNMENT2_BISECTION_H
