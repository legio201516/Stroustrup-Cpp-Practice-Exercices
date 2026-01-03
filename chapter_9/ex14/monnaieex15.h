#include "std_lib_facilities.h"
namespace monney{
enum class Currency {EUR= 1, USD, CD, VND};

class Monnaie{
public : 
    class non_valid_money{};

    Monnaie(long int, long int, Currency c); 
    Monnaie(long int);// basic dollar cents
    Monnaie() : cents{0} { };// 0 dollars
    //Non changing functions
    const long int& get_cents()const { return cents;}
    const long int& get_dolls() const { return cents/100;}
    const double conv_double() const ;
    //Changing functions

private : 
    vector<double> to_doll_conversions {1.1,1.0,0.95,0.0003};
    long int cents;
};
ostream& operator<<(ostream& os, const Monnaie& m);
Monnaie operator*(double d, const Monnaie& m);
Monnaie operator*(const Monnaie& m, double d);
Monnaie operator+(const Monnaie& m, const Monnaie& m2);
int round(double d);//round up or down using the 4/5 rule
istream& operator>>(istream& is, Monnaie& m);


}