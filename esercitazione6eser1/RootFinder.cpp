//
// Created by 39389 on 26/10/2022.
//

#include "RootFinder.h"

RootFinder::RootFinder(const Function &f, unsigned int maxit, real tol, checkT terminationCriteria) : f(f),
                                                                                                      maxit(maxit),
                                                                                                      tol(tol),
                                                                                                      termination_criteria(
                                                                                                              terminationCriteria) {}

bool RootFinder::converged(real increment, real residual,
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