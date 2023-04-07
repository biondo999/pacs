#include <iostream>
#include "math.h"
auto f(double c,double d){
    double b=5;
    return b;
}



int main() {
    using Pf = double(*)(double,double);
    Pf test=f;
    //if you don't add const the object is destroyed
    double const &a=f(3,3);
    std::cout <<a<<"  "<<std::endl;
    return 0;
}
