#include <iostream>
double f(){
    double b=5;
    return b;
}


int main() {
    //if you don't add const the object is destroyed
    double const &a=f();
    std::cout <<a<<"  "<<std::endl;
    return 0;
}
