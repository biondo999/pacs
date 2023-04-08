cmake_minimum_required(VERSION 3.25)
project(assignment2)

set(CMAKE_CXX_STANDARD 17)

add_executable(assignment2 main.cpp SolverBase.cpp SolverBase.h QuasiNewton.cpp QuasiNewton.h Bisection.cpp Bisection.h Secant.cpp Secant.h)
