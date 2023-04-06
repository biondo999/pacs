//
// Created by 39389 on 26/10/2022.
//

#include "Newton.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>
using namespace  std;

real Newton::find_root() const {
    real xp=x0;
    real v = f.eval(xp);
    real xnew;

    bool conv = false;

    for (size_t k = 1; k <= maxit && !conv; ++k) {
        double derv = (f.eval(xp+delta)-f.eval(xp-delta))/(2*delta);
        if (!derv) {
            std::cerr << "ERROR: Division by 0 occurred in Newton algorithm"
                      << std::endl;
            exit(1);
        }

        xnew = xp - v / derv;
        v = f.eval(xnew);
        conv = converged(abs(xnew - xp), abs(v), tol, termination_criteria);
        if (!conv)
            xp = xnew;
        //else std::cout<< "The method converged on the "<<k<<"th iteration of  "<<maxit<<std::endl;
    }


    return xnew;

}






bool Newton::converged(real increment, real residual,
                           real tol, const checkT &check) const{
    /*
      Compares a parameter value against desired tolerance.
      The parameter is chosen upon the value of check.
    */
    switch (check) {
        case INCREMENT:return (increment < tol);
        case RESIDUAL:return (residual < tol);
        case BOTH:return ((increment < tol) && (residual < tol));
        default:return false;
    }
}

void Newton::setX0(real x0) {
    Newton::x0 = x0;
}

void Newton::setDelta(real delta) {
    Newton::delta = delta;
}


void Newton::setMaxit(size_t maxit) {
    Newton::maxit = maxit;
}

void Newton::setTol(real tol) {
    Newton::tol = tol;
}

void Newton::setTerminationCriteria(checkT terminationCriteria) {
    termination_criteria = terminationCriteria;
}

Newton::Newton(real  x0, real delta,container &f, size_t maxit, real tol, checkT terminationCriteria) : x0(x0),
                                                                                                              delta(delta),
                                                                                                              f(f),
                                                                                                              maxit(maxit),
                                                                                                              tol(tol),
                                                                                                              termination_criteria(
                                                                                                                      terminationCriteria) {}






