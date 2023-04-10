//
// Created by mariano on 07/04/23.
//

#ifndef ASSIGNMENT2_SOLVERBASE_H
#define ASSIGNMENT2_SOLVERBASE_H

#include <vector>
#include <functional>
#include <iostream>
#include <cmath>

enum checkT {
    INCREMENT, //! Check the difference between subsequent iterates
    RESIDUAL,  //! Check the residual
    BOTH       //! Check both conditions
};

struct SolverTraits
{
    using ResulType=double;
    using OptionsType=unsigned;
    using IteratorType=std::size_t;
    using Function=std::function<double(ResulType)>;
    using EPSILON=double;
    using ResidualType=checkT;
};



class SolverBase:public SolverTraits{
protected:
    std::vector<ResulType> iteration;
    ResulType final_result;
    Function f;
    IteratorType N_MAX;
    bool converged(double increment, double residual,double tol, const ResidualType &check) const;
    EPSILON epsilon=1e-8;
    ResidualType stopping_condition=BOTH;
    void print_output(double mid,bool found,IteratorType iter,double,double) const;


public:
    virtual void solve()=0;
    virtual ~SolverBase()=default;
    void print_iteration()const ;
};


#endif //ASSIGNMENT2_SOLVERBASE_H
