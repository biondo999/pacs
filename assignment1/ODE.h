//
// Created by mariano on 14/03/23.
//



#ifndef ASSIGNMENT1_ODE_H
#define ASSIGNMENT1_ODE_H


#include "vector"
#include "Newton.h"
#include "iostream"
#include <fstream>
#include "readParameters.hpp"

class ODE {
private:
    std::vector<double> y;
    std::vector<double> x;

    std::function<double(double)> yex;
    std::function<double(double,double)> f;
    double T;
    size_t N;
    double h;
    bool ex=false;
    double y0;
    double theta=0.5;
    void check_input();

public:
    ODE(const std::function<double(double, double)> &f, double t, size_t n, double y0);

    ODE(const std::function<double(double)> &yex, const std::function<double(double, double)> &f, double t,
        size_t n, double y0);
    ODE(std::string  s,const std::function<double(double, double)> &f,const std::function<double(double)> &yex);
    ODE(std::string s,const std::function<double(double, double)> &f);

    ODE()=default;

    void setYex(const std::function<double(double)> &yex);

    void setF(const std::function<double(double, double)> &f);

    void setT(double t);

    void setN(size_t n);

    void setY0(double y0);

    size_t getN() const;

    void setEx(bool ex);

    void solve();

    void print() const;

    void write_result_on_file() const;

    void write_error_on_file() const;

    double helper();


};


#endif //ASSIGNMENT1_ODE_H
