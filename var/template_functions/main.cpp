#include <iostream>
using namespace std;

// One function works for all data types.  This would work
// even for user defined types if operator '>' is overloaded
template <class T>
T myMax(T x, T y)
{
    return (x > y) ? x : y;
}
template <>
char myMax(char x, char y)          //fully specialization can be replace by overloading don't put template<>
{
    return (x < y) ? x : y;
}
template<class T>
auto fun(T a,T b) //auto(implict deduction) or double(explicit deduction)
{
    return a+b;
}


template<class T1,class T2>
double FUN(T1 a,T2 b)
{
    return a+b;
}

int main()
{
    // Call myMax for int
    cout << myMax<int>(3, 7) << endl;
    // call myMax for double
    cout << myMax<double>(3.0, 7.0) << endl;
    // call myMax for char
    cout << myMax<char>('a', 'b') << endl;

    //////
    cout<<"--------------------"<<endl;
    //cout << fun(0.,1) <<std::endl;  no implicit conv
    cout << fun(0.,0.1) <<std::endl;
    cout << FUN(0.3,1) <<std::endl;

    return 0;
}