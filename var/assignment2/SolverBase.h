//
// Created by mariano on 07/04/23.
//

#ifndef ASSIGNMENT2_SOLVERBASE_H
#define ASSIGNMENT2_SOLVERBASE_H

struct SolverTraits
{
    using ResulType=double;
    using OptionsType=unsigned;
};




class SolverBase:public SolverTraits{
public:
    virtual void solve()=0;
};


#endif //ASSIGNMENT2_SOLVERBASE_H
