#include <iostream>
#include "muParser.h"

double MySqr(double a_fVal) {  return a_fVal*a_fVal; }

struct Function{
mu::Parser p;
double x=1;
void init(const std::string &s){p.DefineVar("x", &x);p.SetExpr(s);}
auto operator()(auto a){x=a;return p.Eval();}
};

int main()
{
/*
        double x = 1;
        mu::Parser p;
        std::string s="x*x";
        p.DefineVar("x", &x);
        //p.DefineFun("MySqr", MySqr);
        p.SetExpr(s);
       

        for (std::size_t a=0; a<10; ++a)
        {   x=a;
            std::cout<<p.Eval() <<std::endl;
        }
        */
        std::string s="x*x";
        Function f;  
        f.init(s); 
        s="ciao";

        
        for (std::size_t a=0; a<10; ++a){
            std::cout<<f(a) <<std::endl;
        }
        
        
        
        
        
        
    return 0;
}
