#include "GetPot"
#include "readParameters.hpp"
#include <fstream>
#include "iostream"
parameters
readParameters(std::string const &filename, bool verbose)
{
  // Parameter default constructor fills it with the defaults values
  parameters defaults;
  // checks if file exixts and is readable
  std::ifstream check(filename);
  if(!check)
    {
      std::cerr << "ERROR: Parameter file " << filename << " does not exist"
                << std::endl;
      std::cerr << "Reverting to default values." << std::endl;
      if(verbose)
        std::cout << defaults;
      check.close();
      return defaults;
    }
  else
    check.close();

  GetPot     ifile(filename.c_str());
  parameters values;
  // Read parameters from getpot ddata base
  values.T = ifile("T", defaults.T);
  values.N = ifile("N", defaults.N);
  values.y0 = ifile("y0", defaults.y0);
  values.theta = ifile("theta", defaults.theta);
  if(verbose)
    {
      std::cout << "PARAMETER VALUES IN GETPOT FILE"
                << "\n";
      ifile.print();
      std::cout << std::endl;
      std::cout << "ACTUAL VALUES"
                << "\n"
                << values;
    }
  return values;
}


/*
parameters
readParameters_json(std::string const &filename, bool verbose)
{
  // Parameter default constructor fills it with the defaults values
  parameters defaults;
  // checks if file exixts and is readable
  std::ifstream check(filename);
  if(!check)
    {
      std::cerr << "ERROR: Parameter file " << filename << " does not exist"
                << std::endl;
      std::cerr << "Reverting to default values." << std::endl;
      if(verbose)
        std::cout << defaults;
      check.close();
      return defaults;
    }
  else
    check.close();

  std::ifstream jfile(filename);
  nlohmann::json ifile;
  jfile>>ifile;
  parameters values;
  // Read parameters from getpot ddata base
  values.T = ifile("T", defaults.T);
  values.N = ifile("N", defaults.N);
  values.y0 = ifile("y0", defaults.y0);
  values.theta = ifile("theta", defaults.theta);
  if(verbose)
    {
      std::cout << "PARAMETER VALUES IN JSON FILE"
                << "\n";
      std::cout<<std::setw(4)<<ifile;
      std::cout << std::endl;
      std::cout << "ACTUAL VALUES"
                << "\n"
                << values;
    }
  return values;
}
*/