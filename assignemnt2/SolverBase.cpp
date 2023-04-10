//
// Created by mariano on 07/04/23.
//

#include "SolverBase.h"

bool SolverBase::converged(double increment, double residual,
                       double tol, const ResidualType &check) const{
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

void SolverBase::print_output(double mid, bool found, IteratorType  iter,double increment,double residual) const {
    if(found) std::cout<<"zero found at x = "<<mid<<" in "<<iter<<" iteration/iterations"<<std::endl;
    else std::cout<<"the zero was not found in "<<iter<<" iteration/iterations"<<std::endl;
    std::cout<<"LAST INCREMENT = "<<increment<<std::endl;
    std::cout<<"LAST RESIDUAL = "<<residual<<std::endl;
}

void SolverBase::print_iteration() const {
    for(const auto iter :iteration) std::cout<<"-->"<<iter;
    std::cout<<std::endl;
}
