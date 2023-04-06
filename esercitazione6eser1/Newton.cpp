//
// Created by 39389 on 26/10/2022.
//

#include "Newton.h"
#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>
using namespace  std;

real Newton::find_root(unsigned &nit) const {
    real xp=x0;
    real v = f.eval(xp);
    real xnew;

    bool conv = false;

    for (int k = 1; k <= maxit && !conv; ++k, ++nit) {
        double derv = df.eval(xp);
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
    }
    return xnew;

}



Newton::Newton(const Function &f, unsigned int maxit, real tol, checkT terminationCriteria, real x0, const Function &df)
        : RootFinder(f, maxit, tol, terminationCriteria), x0(x0), df(df) {}
