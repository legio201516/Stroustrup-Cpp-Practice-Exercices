#include "std_lib_facilities.h"
namespace Ratio{
class Rationnal{
    public : 

    Rationnal(int a, int b);
    class Q_is_0{};
    //Non changing functions
    const int& get_num()const { return num;}
    const int& get_denom() const { return denom;}
    const double conv_double() const ;
    //Changing functions
    void reduce();
    void normalize();

    private :
    int num;
    int denom;
    bool is_rational(int, int);
};
ostream& operator<<(ostream& os, const Rationnal& r);
bool operator==(const Rationnal& r1, const Rationnal& r2);
Rationnal operator*(const Rationnal& r1, const Rationnal& r2);
Rationnal operator+(const Rationnal& r1, const Rationnal& r2);
Rationnal operator-(const Rationnal& r1, const Rationnal& r2);
Rationnal operator/(const Rationnal& r1, const Rationnal& r2);


int gcd(int a, int b);
}