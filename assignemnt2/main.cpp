#include <iostream>
#include "Bisection.h"

int main() {
    auto f =[](double x){ return exp(x)-1;};
    SolverTraits::Function g=f;
    Bisection b(-1.5,1,f,100,1e-10,INCREMENT);
    b.solve();
    return 0;
}
