
cmake_minimum_required(VERSION 3.24)
project(assignment1)
include_directories(/home/pacs/pacs-examples/Examples/include/)


set(CMAKE_CXX_STANDARD 17)

add_executable(assignment1 main.cpp ODE.cpp ODE.h Newton.h Newton.cpp parameters.hpp parameters.cpp readParameters.hpp readParameters.cpp GetPot muParser.h)
