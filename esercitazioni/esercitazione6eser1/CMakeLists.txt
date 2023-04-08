cmake_minimum_required(VERSION 3.15)
project(esecitazione6eser1)

set(CMAKE_CXX_STANDARD 14)

add_executable(esecitazione6eser1
        bn_allinone.cpp RootFinder.cpp RootFinder.h Bisection.cpp Bisection.h Newton.cpp Newton.h Function.h
        Function.cpp Robust.cpp Robust.h)
