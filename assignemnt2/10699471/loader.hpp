#include "Factory.hpp"

#include "Bisection.h"
#include "Secant.h"
#include "QuasiNewton.h"

using Abstract=SolverBase;
using Identifier =std::string;
using Builder = std::function<std::unique_ptr<Abstract>()>;
using MyObjectFactory = GenericFactory::Factory<Abstract, Identifier, Builder>;


Builder build1 = [] { return std::make_unique<Bisection>(); };
Builder build2 = [] { return std::make_unique<Secant>(); };
Builder build3 = [] { return std::make_unique<QuasiNewton>(); };


void loadFactory()
{
    auto &factory = MyObjectFactory::Instance();
    factory.add("Bisection", build1);
    factory.add("Secant", build2);
    factory.add("QuasiNewton", build3);
}

