#include <iostream>
#include "Bisection.h"
#include "Secant.h"
#include "math.h"



int main() {
    auto f =[](double x){ return 0.5-exp(PI*x);};
    Bisection b(-1.5,1,f,100,1e-10,INCREMENT);
    b.solve();
    b.write_error_on_file();

    std::cout<<std::endl;
    Secant c(-1.5,1,f,100,1e-10,BOTH,0.75,0.76);
    c.solve();
    c.write_error_on_file();




    return 0;
}
