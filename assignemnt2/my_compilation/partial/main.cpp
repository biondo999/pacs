#include <iostream>
#include "Bisection.h"
#include "Secant.h"
#include "cmath"
#include "Factory.hpp"
#include "Proxy.hpp"


using Abstract=SolverBase;
using Identifier =std::string;
using Builder = std::function<std::unique_ptr<Abstract>()>;
using MyObjectFactory = GenericFactory::Factory<Abstract, Identifier, Builder>;

// Defining the builders for the different concrete objects

Builder build1 = [] { return std::make_unique<Bisection>(); };
Builder build2 = [] { return std::make_unique<Secant>(); };



//! Normally this is done elsewhere, but this is only a test
/*!
  Filling the factory with the first 2 builders
 */

void loadFactory()
{
    auto &factory = MyObjectFactory::Instance();
    factory.add("Bisection", build1);
    factory.add("Secant", build2);
}


int main() {
    /*
    auto f =[](double x){ return 0.5-exp(PI*x);};
    Bisection b(-1.5,1,f,100,1e-10,INCREMENT);
    b.solve();
    b.write_error_on_file();

    std::cout<<std::endl;
    Secant c(-1.5,1,f,100,1e-10,BOTH,0.75,0.76);
    c.solve();
    c.write_error_on_file();
     */

    loadFactory();
    // get the factory
    auto &factory = MyObjectFactory::Instance();
    auto  list = factory.registered();
    std::cout << "Registered identifiers:" << std::endl;
    for(std::size_t i = 0; i < list.size(); ++i)
    {
        std::cout << list[i] << std::endl;
    }

    auto b=factory.create("Bisection");
    b->read_parameters("parameters_bisection");
    b->solve();
    b->write_error_on_file();


    auto c=factory.create("Secant");
    c->read_parameters("parameter_secant");
    c->solve();
    c->write_error_on_file();



    return 0;
}
