//
// Created by 39389 on 26/10/2022.
//



#ifndef ESECITAZIONE6ESER1_BISECTION_H
#define ESECITAZIONE6ESER1_BISECTION_H

#include "RootFinder.h"
typedef double real;

class Bisection:public RootFinder{
protected:
real a;
real b;
public:
    Bisection(const Function &f, unsigned maxit, real tol, checkT terminationCriteria, real a, real b);
    real find_root(unsigned &nit) const;
};


#endif //ESECITAZIONE6ESER1_BISECTION_H
