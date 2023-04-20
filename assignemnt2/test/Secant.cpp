//
// Created by mariano on 07/04/23.
//

#include "Secant.h"
#include "GetPot"
void Secant::solve(){
    bool solvable=true;
    if(f(a)==0) {
        std::cout<<"SECANT_SOLVER: there is a zero at x = "<<a<<"(left extrema)"<<std::endl;
        solvable=false;
    }
    if(f(b)==0) {
        std::cout<<"SECANT_SOLVER: there is a zero at x = "<<b<<"(right extrema)"<<std::endl;
        solvable=false;
    }


    if (f(a)<0 && f(b)<0){
        std::cerr<<"SECANT_SOLVER_ERROR: the interval extrema have the same sign"<<std::endl;
        solvable=false;
    }
    if (f(a)>0 && f(b)>0) {
        std::cerr << "SECANT_SOLVER_ERROR: the interval extrema have the same sign" << std::endl;
        solvable = false;
    }

    if(x0<a || x0>b) solvable= false;
    if(x1<a || x1>b) solvable= false;
    if(f(x0)==0 || f(x1)==0) solvable=false;
    if(x0==x1 || f(x0)==f(x1)) solvable=false;

    if(!solvable) return;

    ResulType x_new;
    ResulType x_old=x1;
    ResulType x_old_old=x0;

    bool found =false;

    IteratorType iter=0;
    double increment=epsilon+1;
    double residual=epsilon+1;
    while (iter<N_MAX && !found){
        x_new=x_old -f(x_old)*(x_old-x_old_old)/(f(x_old)-f(x_old_old));
        iteration.push_back(x_new);
        if(f(x_new)==0) found=true;
        residual=std::abs(f(x_new));
        increment=std::abs(x_new-x_old);
        found=converged(increment,residual,epsilon,stopping_condition);
        x_old_old=x_old;
        x_old=x_new;
        //if(f(x_old)==f(x_old_old)){
        //    found=true;
        //    solvable= false;
        //}
        iter++;
    }
    if (!solvable){
        std::cout<<"SECANT_SOLVER:"<<std::endl;
        std::cout<<"f(x_old) and f(x_old_old) are the same"<<std::endl;
        return;
    }
    std::cout<<"SECANT_SOLVER:"<<std::endl;
    print_output(x_new,found,iter,increment,residual);

    final_result=x_new;

}


void Secant::read_parameters(const std::string &filename) {
    std::ifstream check(filename);
    if(!check)
    {
        std::cerr << "ERROR: Parameter file " << filename << " does not exist"
                  << std::endl;
        std::cerr << "Reverting to default values." << std::endl;
    }
    else
        check.close();
    GetPot ifile(filename.c_str());
    // Read parameters from getpot ddata base
    a = ifile("a", 0);
    b= ifile("b", 0);
    N_MAX = ifile("N_MAX", 0);
    epsilon = ifile("epsilon", 0);
    stopping_condition=static_cast <ResidualType> (ifile("stopping_condition", 1));
    std::cout<<stopping_condition<<std::endl;
    x0= ifile("x0", 0);
    x1= ifile("x1", 0);
    std::string function=ifile("function", "x*x");
    f.init(function);
    s="secant";
}

