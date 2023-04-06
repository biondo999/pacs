//
// Created by 39389 on 29/10/2022.
//

#ifndef ESECITAZIONE6ESER1_ROBUST_H
#define ESECITAZIONE6ESER1_ROBUST_H

#include "RootFinder.h"
class Robust:public RootFinder{
private:
real ratio;
real a;
real b;
Function df;
public:

real find_root(unsigned &nit) const;

Robust(const Function &f, unsigned int maxit, real tol, checkT terminationCriteria, real ratio, real a, real b,
           const Function &df);

};


#endif //ESECITAZIONE6ESER1_ROBUST_H
