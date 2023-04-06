//
// Created by 39389 on 18/10/2022.
//

#ifndef ESERCITAZIONE4ES1_FUNCTION_H
#define ESERCITAZIONE4ES1_FUNCTION_H
#include<vector>
using namespace std;



class Function {
public:
    explicit Function(const vector<double>& f);

private:
    vector<double> f;

public:
    double eval(const double point) const;
    vector<double> derivative() const;
    void print();
};


#endif //ESERCITAZIONE4ES1_FUNCTION_H
