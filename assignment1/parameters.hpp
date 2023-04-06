#ifndef HH_Parameters_HH
#define HH_Parameters_HH
#include <iosfwd>
#include "functional"
/*!
 * A structure holding the parameters
 *
 * It is an aggregate, you can use structured binding and brace initialization
 */
struct parameters
{
  double T = 40.0;
  //! Size of the interval [0,T]
  int N = 10;
  //! Number of points
  double y0 = 1.;
  //! Initial condition
  double theta;
  //! Theta term
};
//! Prints parameters
std::ostream &operator<<(std::ostream &, const parameters &);
#endif
