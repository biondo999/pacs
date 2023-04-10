//
// Created by mariano on 07/04/23.
//

#include "Bisection.h"


void Bisection::solve(){
    bool solvable=true;
    if(f(a)==0) {
        std::cout<<"BISECTION_SOLVER: there is a zero at x = "<<a<<"(left extrema)"<<std::endl;
        solvable=false;
    }
    if(f(b)==0) {
        std::cout<<"BISECTION_SOLVER: there is a zero at x = "<<b<<"(right extrema)"<<std::endl;
        solvable=false;
    }


    if (f(a)<0 && f(b)<0){
        std::cerr<<"BISECTION_SOLVER_ERROR: the interval extrema have the same sign"<<std::endl;
        solvable=false;
    }
    if (f(a)>0 && f(b)>0) {
        std::cerr << "BISECTION_SOLVER_ERROR: the interval extrema have the same sign" << std::endl;
        solvable = false;
    }


    if(!solvable) return;

    double pos;
    double neg;
    if(f(a)>0) {
        pos=a;
        neg=b;
    }
    else{pos=b;neg=a;}

    bool found =false;
    double mid;
    IteratorType iter=0;
    double increment=epsilon+1;
    double residual=epsilon+1;
    while (iter<N_MAX && !found){
        mid=(pos+neg)/2;
        iteration.push_back(mid);
        if(f(mid)==0) found=true;
        else (f(mid)>0) ? pos=mid:neg=mid;
        residual=std::abs(f(mid));
        if(iter>1) increment=std::abs(iteration[iter]-iteration[iter-1]);
        iter++;
        found=converged(increment,residual,epsilon,stopping_condition);
    }

    std::cout<<"BISECTION_SOLVER:"<<std::endl;
    print_output(mid,found,iter,increment,residual);

    final_result=mid;

}


