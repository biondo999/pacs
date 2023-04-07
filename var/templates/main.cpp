#include <iostream>
#include <array>
#include <complex>
#include <vector>
using namespace  std;

//template <size_t N,class T> class Point
template <size_t N=1,class T=double> class Point  //default values
        {
                public :
                Point(array<double ,N> p,T t) : data{p},t(t){};
                Point () = default ;
                private :
                array<double ,N> data ;
                T t;
        };

int main() {
    Point<4,int> p1({1,2,3,4},1);
    Point<4,unsigned> p2;
    std::vector<complex<double>> i;
    return 0;
}
