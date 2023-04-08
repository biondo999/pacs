//
// Created by 39389 on 26/10/2022.
//

#include "Bisection.h"
#include <limits>
#include <cstdlib>
#include <iostream>
#include <cmath>
using namespace std;


real Bisection::find_root(unsigned &nit) const{
    real u = f.eval(a);  // Evaluate f on boundary a
    real l = b - a; // Interval length
    real r;         // Residual
    real c = a + l;   // Middle point
    r = f.eval(c);

    if (u * f.eval(b) >= 0.0) {
        std::cout << "Error Function has same sign at both endpoints" << std::endl;
        return -std::numeric_limits<double>::infinity();
    }
    real A=a;
    real B=b;

    while (!(converged(abs(l),abs(r),tol,termination_criteria))
           && (nit <= maxit)) {
        /*
          If f(c)f(a) < 0 then the new "right" boundary is c;
          otherwise move the "left" boundary

          The expression
             test ? stat1 : stat2
          means
             if(test)
                stat1
             else
                stat2
        */
        (u * r < 0.) ? (B = c) : (A = c, u = r);
        l *= 0.5;
        c = A + l;
        r = f.eval(c);
        ++nit;
    }
    return c;
}





Bisection::Bisection(const Function &f, unsigned  maxit, real tol, checkT terminationCriteria, real a, real b)
        : RootFinder(f, maxit, tol, terminationCriteria), a(a), b(b) {}
