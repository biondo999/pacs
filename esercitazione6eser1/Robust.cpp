//
// Created by 39389 on 29/10/2022.
//

#include "Robust.h"
#include "Bisection.h"
#include "Newton.h"




real Robust::find_root(unsigned &nit)const {

Bisection B(f,maxit,ratio*tol,termination_criteria,a,b);

real x_B=B.find_root(nit);

Newton N(f,maxit,tol,termination_criteria,x_B,df);

return N.find_root(nit);

}

Robust::Robust(const Function &f, unsigned int maxit, real tol, checkT terminationCriteria, real ratio, real a, real b,
               const Function &df) : RootFinder(f, maxit, tol, terminationCriteria), ratio(ratio), a(a), b(b),
                df(df) {}
