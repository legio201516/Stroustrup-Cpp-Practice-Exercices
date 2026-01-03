#include "std_lib_facilities.h"


struct Date {
    int y ;
    int m;
    int d;
};

void init_day(Date& dd,int y, int m, int d){
    if (m<1 || m>12) error("init_day: Invalid month");
    if (d<1 || d>31) error("init_day: Invalid day");
    dd.y=y;
    dd.d=d;
    dd.m=m;
    }
void add_day(Date& dd, int n){
    if (dd.d + n>31) {dd.m++; dd.d+=-31+n;}
    else dd.d+=n;
}
ostream& operator<<(ostream& os, const Date& d){
    return os<< '('<<d.y<<','<<d.m<<',' << d.d<<')'<< endl;
}
Date today;

int main()try {
   init_day(today, 1978,06,25);
   cout << today;
   Date tomorrow=today;
   add_day(tomorrow,10);
   cout << tomorrow;
    Date wrong;
    init_day(wrong, 1978,12,-5);
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