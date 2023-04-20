#include <iostream>
#include<cmath>
#include "ODE.h"
#include "muParser.h"




int main() {
    auto f= [ ] ( double  t,double y){ return -t*exp( -y);};
    auto yex= [ ] ( double t){ return log(1-(t*t)*0.5);};


    std::cout << "ODE SOLVER" << std::endl;

    ODE TEST("parameters.pot",f,yex);
    TEST.solve();
    TEST.write_result_on_file();
    TEST.write_error_on_file();







    return 0;
}
