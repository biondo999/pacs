/*!
 * \file bn-allinone.cpp
 * \brief all the exercise code in a single file. Original version by Luca Formaggia
 * \date Oct 14, 2016
 */

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <limits>
#include "Function.h"
#include "RootFinder.h"
#include "Bisection.h"
#include "Newton.h"
#include "Robust.h"


//! Type for real numbers
typedef double real;


//! Type for convergence check


//! Function f(x)
real f(real x) {
  return pow(x, 2) - 0.5;
}

//! First derivative of function f(x) 
real df(real x) {
  return 2. * x;
}

bool converged(real increment, real residual,
               real tol, const checkT &check) {
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

// BISECTION METHOD
real bisection(real a, real b,
               real tol, int maxit,
               const checkT &check, int &nit) {
  real u = f(a);  // Evaluate f on boundary a
  real l = b - a; // Interval length
  real r;         // Residual
  real c = a + l;   // Middle point

  nit = 0;
  r = f(c);

  if (u * f(b) >= 0.0) {
    std::cout << "Error Function has same sign at both endpoints" << std::endl;
    return -std::numeric_limits<double>::infinity();
  }

  while (!(converged(fabs(l), fabs(r), tol, check))
      && (nit <= maxit)) {
    /*
      If f(c)f(a) < 0 then the new "right" boundary is c;
      otherwise move the "left" boundary

      The expression
         test ? stat1 : stat2
      means
         if(test)
            stat1
         else
            stat2
    */
    (u * r < 0.) ? (b = c) : (a = c, u = r);
    l *= 0.5;
    c = a + l;
    r = f(c);
    ++nit;
  }
  return c;
}

// NEWTON METHOD
real newton(real xp, real tol, int maxit,
            const checkT &check, int &nit) {
  real v = f(xp);
  real xnew;

  nit = 0;
  bool conv = false;

  for (int k = 1; k <= maxit && !conv; ++k, ++nit) {
    double derv = df(xp);
    if (!derv) {
      std::cerr << "ERROR: Division by 0 occurred in Newton algorithm"
                << std::endl;
      exit(1);
    }

    xnew = xp - v / derv;
    v = f(xnew);
    conv = converged(fabs(xnew - xp), fabs(v), tol, check);
    if (!conv)
      xp = xnew;
  }
  return xnew;

}

// ROBUST METHOD
real robust(real a, real b,
            real tol, real cfratio,
            int maxit, const checkT &check,
            int &nit_coarse, int &nit_fine) {
  // Call bisection method (with a greater desired tolerance)
  real tol_bis = cfratio * tol;
  real x_bis = bisection(a, b, tol_bis, maxit, check, nit_coarse);

  /*
    Call a Newton algorithm which uses as an initial value
    the solution given by bisection method
  */
  return newton(x_bis, tol, maxit, check, nit_fine);
}

// MAIN FUNCTION
int main() {

  int nit_bis;
  int nit_newt;
  std::cout << std::numeric_limits<double>::infinity() << std::endl;
  std::cout << "Bisection" << std::endl;
  std::cout << bisection(0., 1., 1e-8, 100, RESIDUAL, nit_bis);
  std::cout << '\t' << nit_bis << std::endl;

  std::cout << "Newton" << std::endl;
  std::cout << newton(.1, 1e-8, 100, RESIDUAL, nit_newt);
  std::cout << '\t' << nit_newt << std::endl;

  std::cout << "Robust" << std::endl;
  std::cout << robust(0., 1., 1e-8, 1e4, 100, RESIDUAL, nit_bis, nit_newt);
  std::cout << '\t' << nit_bis << " " << nit_newt << std::endl;


  std::cout << '\t' << std::endl;

  unsigned Nit_bis=0;
  unsigned Nit_newt=0;
  unsigned Nit_rob=0;

  Function f({-0.5,0,1});
  Function df({0,2});


  std::cout << "Bisection" << std::endl;
  Bisection B(f,100, 1e-8,RESIDUAL,0.,1.);
  std::cout << B.find_root(Nit_bis);
  std::cout << '\t' << Nit_bis << std::endl;


  std::cout << "Newton" << std::endl;
  Newton N(f,100,1e-8,RESIDUAL,0.1,df);
  std::cout << N.find_root(Nit_newt);
  std::cout << '\t' << Nit_newt << std::endl;



  std::cout << "Robust" << std::endl;
  Robust R(f,100,1e-8,RESIDUAL,1e4,0.,1,df);
  std::cout << R.find_root(Nit_rob);
  std::cout << '\t' << Nit_rob << std::endl;











  return 0;
}
