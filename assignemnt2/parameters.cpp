#include "parameters.hpp"
#include <iostream>
std::ostream &
operator<<(std::ostream &out, const parameters &p)
{
  out << "PARAMETER VALUES:"
      << "\n";
  out << "interval size= " << p.T << "\n";
  out << "number of points= " << p.N << "\n";
  out << "initial condition= " << p.y0 << "\n";
  out << "theta term= " << p.theta << "\n";
  return out;
}
