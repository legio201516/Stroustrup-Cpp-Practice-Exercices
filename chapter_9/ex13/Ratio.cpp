# include "Ratio.h"

namespace Ratio{
int gcd(int a, int b) 
// Find greatest common divisor by Euclidean algorithm
{
    a = abs(a);     // we need natural (positive numbers)
    b = abs(b);
    if (b > a) swap(a, b);  // we need a to be the greatest of both

    while (b != 0) {
        int t{b};
        b = a % b;
        a = t;
    }
    return a;
}
Rationnal::Rationnal(int a, int b)
: num(a), denom(b)
{
    if (b==0) throw Q_is_0();
    normalize();
    reduce();

}
void Rationnal::normalize()
{
    if (denom < 0) {  // if denominator is negative do it positive
        denom = -denom;
        num = -num; // and change the sign of numerator
    }
}
void Rationnal::reduce()
{   int n =gcd(num,denom);
    num/=n;
    denom/=n;
}
const double Rationnal::conv_double()const
{   cout << num<<denom<< " num/denom";
    return double(num)/denom;
}


ostream& operator<<(ostream& os, const Rationnal& r)
{
    return os<< r.get_num()<< '/'<< r.get_denom()<< endl;
}
bool operator==(const Rationnal& r1, const Rationnal& r2)
{
    if ((r1.get_num()==r2.get_num()) && (r1.get_denom()==r2.get_denom())) return true;
    return false;
}
Rationnal operator*(const Rationnal& r1, const Rationnal& r2)
{
    int a = r1.get_num()*r2.get_num();
    int b = r1.get_denom()*r2.get_denom();
    return Rationnal(a,b);
}
Rationnal operator+(const Rationnal& r1, const Rationnal& r2)
{
    int a = (r1.get_num()*r2.get_denom())+(r2.get_num()*r1.get_denom());
    int b = r1.get_denom()*r2.get_denom();
    return Rationnal(a,b);
}
Rationnal operator/(const Rationnal& r1, const Rationnal& r2)
{
    int a = r1.get_num()*r2.get_denom();
    int b = r1.get_denom()*r2.get_num();
    return Rationnal(a,b);
}
Rationnal operator-(const Rationnal& r1, const Rationnal& r2)
{
    return r1+Rationnal(-r2.get_num(), r2.get_denom());
}

}