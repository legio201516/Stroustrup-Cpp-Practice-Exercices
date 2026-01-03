# include "monnaieex15.h"
namespace monney{

Monnaie::Monnaie(long int a, long int b, Currency c)
{   if (a<0|| b<0)throw non_valid_money();
    int i = int(c);
    cents= to_doll_conversions[i]*100*a +b;

}
Monnaie::Monnaie(long int a)// constructor for input cents in dollars
:cents(a)
{   if (a<0)throw non_valid_money();
}

int round(double d)// we round up a double value of cents : 
{   int n= int(d);
    cout <<"Hello we round your number" << n;
    return (d-n <= 0.5) ? (n) : (n +1);
}

Monnaie operator*(double d, const Monnaie& m)
{   long int a= round(d*m.get_cents());
    return Monnaie(a);
}

ostream& operator<<(ostream& os, const Monnaie& r)
{
    int doll=r.get_cents()/100;int centtts=r.get_cents()%100;
    return os<<'$'<< doll<< '.'<< centtts << endl;
}
Monnaie operator*(const Monnaie& m, double d)
{
    return d*m;
}
Monnaie operator+(const Monnaie& m, const Monnaie& m2)
{
    return Monnaie(m.get_cents()+m2.get_cents());
}

istream& operator>>(istream& is, Monnaie& m)
{   cout << " Please enter a value like $1.23, or £34.00 :";
    long int units{0};
    char cur, dot;
    char d, u;//cents

    is >> cur >> units >> dot >> d >> u;
    if (!is) return is;

    if (cur !='$'&& cur!='£') {
        cin.clear(ios_base::failbit);
        cout << " currency ($ or £ needed first )"; 
        return is;}

    int c{(d-'0')*10+(u-'0')};
    m=Monnaie(units,c, Currency::USD);
    return is;
}


}