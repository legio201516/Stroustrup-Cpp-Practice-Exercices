#include "Chrono.h"
namespace Chrono{

Date::Date(int yy, Month mm, int dd)
:y(yy), m(mm), d(dd)
{
    if (!is_date(yy, mm, dd)) throw Invalid();
}
Date& default_date()
{
    static Date dd(2001, Month::jan, 1);
    return dd;
}

Date::Date()
:y(default_date().year()), m(default_date().month()), d(default_date().day())
{
}
void Date::add_day(int n){
     if (d + n>31) {
        m=Month(m+1); d+=-31+n;}
    else d+=n;
}
void Date::add_month(int n){
    int mm= int(m);
    if (mm+n>12) {// we get a new year;
        y+=1;
        m=Month(mm+n-12);
    }
    else m=Month(m+n);
}

void Date::add_year(int n){
    y+=n;
}
bool is_date(int y, Month m, int d){
    if (d<=0) return false;
    int days_in_month=31;
    switch(m){
        case Month::feb:
        days_in_month=29;
        break;
        case Month::apr: case Month::jun: case Month::sep: case Month::nov:
        days_in_month=30;
        break;
    }
    if (days_in_month<d) return false;
    if (m>Month::dec||m<Month::jan) return false;
    return true;
}

bool operator==(const Date& a, const Date& b)
{
    return a.year()==b.year()
    && a.month()==b.month()
    && a.day()==b.day();
}
bool operator!=(const Date& a, const Date& b)
{
    return !(a==b);
}
ostream& operator<<(ostream& os, const Date& d)
{
    return os << '('<< d.year()<< ','<< d.month()<< ','<< d.day()<<')';
}
istream& operator>>(istream& is,  Date& dd)
{
    int y, m, d;
    char ch1, ch2, ch3, ch4;
    is>>ch1>> y>>ch2>>m>> ch3>>d>> ch4;
    if (!is) return is;
    if (ch1!='('||ch2!=','|| ch3!=','|| ch4!=')') {
        is.clear(ios_base::failbit);
        return is;}
    dd=Date(y, Month(m), d);
    return is;
}
bool leapyear(int y )
{
    if (y%4==0) return true;
    return false;
}
Date next_Sunday(const Date& d)
{
    Date date_copy= d;
    while (date_copy.day()!=sun)
    date_copy.add_day();
}

}