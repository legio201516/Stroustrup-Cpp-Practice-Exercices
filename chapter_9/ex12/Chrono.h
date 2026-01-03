#include "std_lib_facilities.h"

#ifndef CHRONO_H    // Since this header is included on two .cpp files
#define CHRONO_H    // an include guard must be issued

namespace Chrono{
    enum Month{jan=1, feb, mar, apr,may, jun, jul, aug, sep, oct, nov, dec};
    enum day_of_week{ mon=1, tue, wed, thu, fri, sat, sun};
    class Date {
    public: 
        class Invalid{};
        
        Date(int y, Month m, int d);//initiises and checks correctness
        Date();//by default
        // non changing ops
        Month month()const{ return m;}
        int year()const{ return y;}
        int day ()const {return d;}

        //changing ops 
        void add_day(int n);
        void add_month(int n);
        void add_year(int n);
    private:
        int y ;
        Month m;
        int d;
    };

    bool is_date(int y, Month m,int d);// true if valid date
    bool leapyear(int y );
    bool operator==(const Date& a, const Date& b);
    bool operator!=(const Date& a, const Date& b);
    Date next_Sunday(const Date& d);
    Date next_workday(const Date& a);
    ostream& operator<<(ostream& os, const Date& d);
    istream& operator>>(istream& is,  Date& dd);
}

#endif