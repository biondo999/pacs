//
// Created by mariano on 07/04/23.
//

#include "QuasiNewton.h"

#include "Bisection.h"
#include "GetPot"

void QuasiNewton::solve(){
    bool solvable=check_extrema();

    if(x0<a || x0>b){
    	solvable= false;
    	std::cerr << "SOLVER_ERROR: the initial guess is outside the interval" << std::endl;
    		}
    			
    if(!solvable) return;
    
    

    double delta=0.000001;
    bool found =false;
    double x_old=x0;
    double x_new;
    
    if(f(x0==0)) {
		found==true;
	}  


    IteratorType iter=0;
    double increment=epsilon+1;
    double residual=epsilon+1;
    while (iter<N_MAX && !found){

    	double first_derivative=(f(x_old+delta)-f(x_old-delta))/(2*delta);
    	
    	
        if (first_derivative==0) {
        std::cout<<"the first derivative of f at the point x = "<<x_old<<" is zero"<<std::endl;
        break;
        }

	
        double h=-f(x_old)/first_derivative;
        x_new=x_old+h;
        
        iteration.push_back(x_new);
        if(f(x_new)==0) found=true;
        residual=std::abs(f(x_new));
        if(iter>1) increment=std::abs(iteration[iter]-iteration[iter-1]);
        iter++;
        found=converged(increment,residual,epsilon,stopping_condition);
        x_old=x_new;
    }

    std::cout<<"SOLVER:"<<std::endl;
    print_output(x_new,found,iter,increment,residual);

    final_result=x_new;

}


void QuasiNewton::read_parameters(const std::string &filename) {
    std::ifstream check(filename);
    if(!check)
    {
        std::cerr << "ERROR: Parameter file " << filename << " does not exist"
                  << std::endl;
        std::cerr << "Reverting to default values." << std::endl;
    }
    else check.close();
    GetPot ifile(filename.c_str());
    //parameters values;
    // Read parameters from getpot ddata base
    a = ifile("a", 0.);
    b= ifile("b", 0.);
    N_MAX = ifile("N_MAX", 0);
    epsilon = ifile("epsilon", 0.);
    stopping_condition=static_cast <ResidualType> (ifile("stopping_condition", 1));
    std::string function=ifile("function", "x*x");
    f.init(function);
    s="QuasiNewton";
    x0 = ifile("x0", 0.);
    save_error = ifile("save_error", false);
    exact_sol = ifile("exact_sol", 0.);
}



