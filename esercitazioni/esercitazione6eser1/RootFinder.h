//
// Created by 39389 on 26/10/2022.
//

#ifndef ESECITAZIONE6ESER1_ROOTFINDER_H
#define ESECITAZIONE6ESER1_ROOTFINDER_H
#include "Function.h"


typedef double real;

enum checkT {
    INCREMENT, //! Check the difference between subsequent iterates
    RESIDUAL,  //! Check the residual
    BOTH       //! Check both conditions
};


class RootFinder {
protected:
Function f;
unsigned maxit;
real tol;
checkT termination_criteria;
bool converged(real increment,real residual,real tol, const checkT &check) const;
public:
RootFinder(const Function &f, unsigned int maxit, real tol, checkT terminationCriteria);

};


#endif //ESECITAZIONE6ESER1_ROOTFINDER_H
