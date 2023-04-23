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


bool SolverBase::check_extrema(){
    bool solvable=true;
    if(f(a)==0) {
        std::cout<<s+"SOLVER: there is a zero at x = "<<a<<"(left extremum)"<<std::endl;
        solvable=false;
    }
    if(f(b)==0) {
        std::cout<<s+"SOLVER: there is a zero at x = "<<b<<"(right extremum)"<<std::endl;
        solvable=false;
    }


    if (f(a)<0 && f(b)<0){
        std::cerr<<s+"SOLVER_ERROR: the interval extrema have the same sign"<<std::endl;
        solvable=false;
    }
    if (f(a)>0 && f(b)>0) {
        std::cerr << s+"SOLVER_ERROR: the interval extrema have the same sign" << std::endl;
        solvable = false;
    }
    return solvable;
}



void SolverBase::print_output(double mid, bool found, IteratorType  iter,double increment,double residual) const {
    if(found) std::cout<<"zero found at x = "<<mid<<" in "<<iter<<" iteration/iterations"<<std::endl;
    else std::cout<<"the zero was not found in "<<iter<<" iteration/iterations"<<std::endl;
    std::cout<<"LAST INCREMENT = "<<increment<<std::endl;
    std::cout<<"LAST RESIDUAL = "<<residual<<std::endl;
}

void SolverBase::print_iteration() const {
    for(const auto iter :iteration){
     std::cout<<"--> x ="<<iter;
     }
    std::cout<<std::endl;
}

void SolverBase::write_error_on_file() const{
    if(save_error){
    ResulType ex;
    ex=exact_sol;
    //std::cout<<"type the real zero -> ";
    //std::cin>>ex;
    std::cout<<"SAVING ERROR ON FILE"<<std::endl;
    std::cout << "Error file: "<<"error_"+s+".dat"<<std::endl;
    std::ofstream f("error_"+s+".dat");
    // In gnuplot lines beginning with # are comments
    // \t writes a tab
    f << "#number_of_iteration\titeration_error\tupper_bound_in_bisection" << std::endl;
    for (IteratorType m = 0; m < iteration.size(); m++) {
        f.setf(std::ios::left, std::ios::adjustfield);
        f.width(16);
        f << m+1 << "\t\t" << std::abs(iteration[m]-ex) << "\t\t" << (b-a)/pow(2,m+1)<< "\n";
    }
    f.close();
    std::cout<<"\n";
                 }
                 }

