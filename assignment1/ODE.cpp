//
// Created by mariano on 14/03/23.
//

#include "ODE.h"
#include <iostream>
#include "cmath"


ODE::ODE(const std::function<double(double, double)> &f, double t, size_t n, double y0) : f(f), T(t), N(n), y0(y0) {ex=false;h=T/N;y.resize(N+1,0);x.resize(N+1,0);check_input();}

ODE::ODE(const std::function<double(double)> &yex, const std::function<double(double, double)> &f, double t,
         size_t n, double y0) : yex(yex), f(f), T(t), N(n),y0(y0) {ex= true;y.resize(N+1,0);h=T/N;x.resize(N+1,0);check_input();}

void ODE::setYex(const std::function<double(double)> &yex) {
    ODE::yex = yex;
    ex=true;
}

void ODE::setF(const std::function<double(double, double)> &f) {
    ODE::f = f;
}

void ODE::setT(double t) {
    T = t;
    h=T/N;
}

void ODE::setN(size_t n) {
    N = n;
    y.resize(N+1,0);
    x.resize(N+1,0);
    h=T/N;
}

void ODE::setY0(double y0) {
    ODE::y0 = y0;
}

void ODE::solve() {
    size_t iter=0;
    y[0]=y0;
    x[0]=0;
    container F;
    F.g=f;
    F.h=h;
    F.theta=theta;
    Newton C(F.un,h/1000,F,100,1e-8,RESIDUAL);
    while(iter<x.size()-1){
    F.tn=0+(h*iter);
    F.un=y[iter];
    C.setX0(F.un);
    iter++;
    y[iter]= C.find_root();
    x[iter]=(h*iter);
    }
}

void ODE::print() const {
    std::cout<<"t"<<std::endl;
    for(size_t i=0;i<y.size();i++) std::cout<<x[i]<<" ";

    std::cout<<std::endl<<"ynum"<<std::endl;
    for(size_t i=0;i<y.size();i++) std::cout<<y[i]<<" ";
    std::cout<<std::endl<<"yex"<<std::endl;
    if(ex) {
        for (size_t i = 0; i < y.size(); i++) std::cout << yex(0 + h * i) << " ";
        std::cout << std::endl;
    }
}

void ODE::write_result_on_file() const {
    if(ex){
        std::cout<<"Do you want also the exact solution also saved on the file ?(type y for yes)"<<std::endl;
        std::string err;
        std::cin>>err;
        std::cout<<std::endl;
    if (err=="y") {
        std::cout<<"SAVING RESULT ON FILE"<<std::endl;
        std::cout << "Result file: result.dat" << std::endl;
        std::ofstream f("result.dat");
        // In gnuplot lines beginning with # are comments
        // \t writes a tab
        f << "#node coordinate\tcomputed solution\texact solution" << std::endl;
        for (int m = 0; m <= N; m++) {
            f.setf(std::ios::left, std::ios::adjustfield);
            f.width(16);
            f << x[m] << "\t\t" << y[m] << "\t\t" << yex(x[m]) << "\n";
        }
        f.close();
    }
    else{
        std::cout<<"SAVING RESULT ON FILE"<<std::endl;
        std::cout << "Result file: result.dat" << std::endl;
        std::ofstream f("result.dat");
        // In gnuplot lines beginning with # are comments
        // \t writes a tab
        f << "#node coordinate\tcomputed solution" << std::endl;
        for (int m = 0; m <= N; m++) {
            f.setf(std::ios::left, std::ios::adjustfield);
            f.width(16);
            f << x[m] << "\t\t" << y[m] << "\n";
        }
        f.close();
    }
    }
    else{
        std::cout<<"SAVING RESULT ON FILE"<<std::endl;
        std::cout << "Result file: result.dat" << std::endl;
        std::ofstream f("result.dat");
        // In gnuplot lines beginning with # are comments
        // \t writes a tab
        f << "#node coordinate\tcomputed solution" << std::endl;
        for (int m = 0; m <= N; m++) {
            f.setf(std::ios::left, std::ios::adjustfield);
            f.width(16);
            f << x[m] << "\t\t" << y[m] << "\n";
        }
        f.close();
    }
}

void ODE::setEx(bool ex) {
    ODE::ex = ex;
}

void ODE::write_error_on_file() const {
    if(!ex) return;
    std::vector<double> error;
    std::vector<double> one_over_n;
    ODE temp(*this);
    for(size_t j =2;j<=10;j++){
        temp.setN(pow(2,j));
        temp.solve();
        one_over_n.push_back(1./pow(2,j));
        error.push_back(temp.helper());
    }
    std::cout<<"SAVING ERROR ON FILE"<<std::endl;
    std::cout << "Error file: error.dat" << std::endl;
    std::ofstream f("error.dat");
    // In gnuplot lines beginning with # are comments
    // \t writes a tab
    f << "#node 1/N\terror" << std::endl;
    for (int m = 0; m < error.size(); m++) {
        f.setf(std::ios::left, std::ios::adjustfield);
        f.width(16);
        f << one_over_n[m] << "\t\t" << error[m] << "\n";
    }
    f.close();
}

double ODE::helper(){
    double err_old=-1;
    double err_new;
    for(size_t i=0;i<x.size();i++) {
        err_new =(yex(x[i]) - y[i]);
        if (err_new<0) err_new=-err_new;
        if (err_new > err_old) err_old = err_new;
    }
    return err_old;
}

ODE::ODE(std::string s, const std::function<double(double, double)> &f,
         const std::function<double(double)> &yex) : f(f),yex(yex) {
parameters p=readParameters(s,false);
N=p.N;
T=p.T;
theta=p.theta;
y0=p.y0;
ex=true;
h=T/N;
y.resize(N+1,0);
x.resize(N+1,0);
check_input();
std::cout<<p<<std::endl;
}

ODE::ODE(std::string s, const std::function<double(double, double)> &f) : f(f) {
    parameters p=readParameters(s,true);
    N=p.N;
    T=p.T;
    theta=p.theta;
    y0=p.y0;
    h=T/N;
    y.resize(N+1,0);
    x.resize(N+1,0);
    check_input();
    std::cout<<p<<std::endl;
}

void ODE::check_input() {
if(T<0){
    T=1;
    std::cout<<"THE SIZE OF THE INTERVAL IS NEGATIVE,SO IT IS ASSIGNED TO DEFAULT VALUE(T=1)"<<std::endl;
}

if(theta<0 || theta >1){
    theta=0.5;
    std::cout<<"THETA IS NOT BETWEEN 0 AND ONE,SO IT IS ASSIGNED TO DEFAULT VALUE(Theta=0.5)"<<std::endl;

}
}

size_t ODE::getN() const {
    return N;
}

