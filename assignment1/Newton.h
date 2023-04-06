//
// Created by 39389 on 26/10/2022.
//


#ifndef ASSIGNMENT1_NEWTON_H
#define ASSIGNMENT1_NEWTON_H

#include "functional"


typedef double real;
typedef std::function<double(double)> Function;
enum checkT {
    INCREMENT, //! Check the difference between subsequent iterates
    RESIDUAL,  //! Check the residual
    BOTH       //! Check both conditions
};

struct container{
    real h;
    real tn;
    real un;
    real theta;
    std::function<double(double,double)> g;
    real eval(double x)const{
        return x-(h)*(theta*g(tn+h,x)+(1-theta)*g(tn,un))-un;
    }
};


class Newton{
private:
    real  x0;
    real delta;
    container & f;
    size_t maxit;
    real tol;
    checkT termination_criteria;
    bool converged(real increment,real residual,real tol, const checkT &check) const;

public:

    Newton(real x0, real delta,container &f, size_t maxit, real tol, checkT terminationCriteria);

    void setX0(real x0);

    void setDelta(real delta);


    void setMaxit(size_t maxit);

    void setTol(real tol);

    void setTerminationCriteria(checkT terminationCriteria);

    real find_root() const;
};


#endif
