//
// Created by mariano on 07/04/23.
//

#include "Secant.h"
#include "GetPot"
void Secant::solve(){
    bool solvable=check_extrema();
   
 
    if(x0<a || x0>b) {
    			solvable= false;
    			std::cerr <<"SOLVER_ERROR: the initial point x0 is outside the interval" << std::endl;
    			}
    if(x1<a || x1>b) {
    			solvable= false;
    			std::cerr << "SOLVER_ERROR: the initial point x1 is outside the interval" << std::endl;
    			}
    			
    if(f(x0)==0){ solvable=false;
    		  std::cerr << "SOLVER_ERROR: the initial point x0 = "<<x0<<" is a zero" << std::endl;
    		  }
    		  
    if(f(x1)==0){ solvable=false;
    		  std::cerr << "SOLVER_ERROR: the initial point x1 = "<<x1<<" is a zero" << std::endl;
    		  }
    		  
    if(x0==x1) {		solvable=false;
    			    	std::cerr << "SOLVER_ERROR: the points x1 and x0 are the same point" << std::endl;
    			    	}
    if(f(x0)==f(x1)) {		solvable=false;
    			    	std::cerr << "SOLVER_ERROR: the points x1 and x0 have the same value f(x)" << std::endl;
    			    	}			    	
    			    		

    if(!solvable) return;
    ResulType x_old=x1;
    ResulType x_old_old=x0;
    ResulType x_new;
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
        iter++;
    }
    if (!solvable){
        std::cout<<"SOLVER:"<<std::endl;
        std::cout<<"f(x_old) and f(x_old_old) are the same"<<std::endl;
        return;
    }
    std::cout<<"SOLVER:"<<std::endl;
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
    a = ifile("a", 0.);
    b= ifile("b", 0.);
    N_MAX = ifile("N_MAX", 0.);
    epsilon = ifile("epsilon", 0.);
    stopping_condition=static_cast <ResidualType> (ifile("stopping_condition", 1));
    std::string function=ifile("function", "x*x");
    x0= ifile("x0", 0.);
    x1= ifile("x1", 0.);
    f.init(function);
    s="Secant";
    save_error = ifile("save_error", false);
    exact_sol = ifile("exact_sol", 0.);
    
}

