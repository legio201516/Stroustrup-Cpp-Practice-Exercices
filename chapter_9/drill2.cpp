#include "std_lib_facilities.h"


struct Date {
    int y ;
    int m;
    int d;
    Date(int y,int m, int d);
    void add_day(int n);
};

Date::Date(int yy, int mm, int dd){
    if (mm<1 || mm>12) error("init_day: Invalid month");
    if (dd<1 || dd>31) error("init_day: Invalid day");
    d=dd;
    y=yy;
    m=mm;
}
void Date::add_day(int n){
     if (d + n>31) {m++; d+=-31+n;}
    else d+=n;
}

ostream& operator<<(ostream& os, const Date& d){
    return os<< '('<<d.y<<','<<d.m<<',' << d.d<<')'<< endl;
}

int main()
    try {
    Date today(1978,06,25);
    cout << today;
    Date tomorrow=today;
    tomorrow.add_day(10);
    cout << tomorrow;
    Date wrong(1978,12,-5);
    cout << wrong;

    return 0;
}
catch (exception& e ){
    cerr<< e.what()<< endl;
    return 1;
}
catch (...){
    cerr<< "Unknown exception !"<< endl;
    return 2;
}