//
// Created by 39389 on 26/10/2022.
//

#ifndef ESECITAZIONE6ESER1_NEWTON_H
#define ESECITAZIONE6ESER1_NEWTON_H

#include "RootFinder.h"
class Newton:public RootFinder {
protected:
    real x0;
    Function df;
public:
    Newton(const Function &f, unsigned int maxit, real tol, checkT terminationCriteria, real x0, const Function &df);
    real find_root(unsigned &nit) const;
};


#endif //ESECITAZIONE6ESER1_NEWTON_H
