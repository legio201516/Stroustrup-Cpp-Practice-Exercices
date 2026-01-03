// 9.exercise.11.cpp
//
//  Design and implement a set of useful helper functions for the Date class
//  with functions such as next_workday() (assume that any day that is not a
//  Saturday or a Sunday is a workday) and week_of_year() (assume that week 1
//  is the week with January 1 in it and that the first day of a week is a
//  Sunday).
//
// COMMMENTS
//
//  next_workday() is presented in §9.8 as next_weekday(). I'll replace it.
//  To implement these functions, day_of_week() and next_Sunday() seem
//  convenient.
//
//  To simplify a bit and seeing that the next exercise tell us to change
//  representation to the number of days since January, the first 1970 (the
//  "epoch") and since managing dates previous to that implies negative numbers
//  and added complexity, I'll restrict date to be posterior to the epoch.
//
//  I also define +, += and << operators for Day, a ++ operator for Month, <
//  and <= operator for Date and a month_days() that returns the days of a
//  month.
//
//  day_of_week() could be implemented more efficiently, of course. But I
//  choose the finger count.
//
//  For next_Sunday() to work, and thus week_of_year(), Date::add_day() must be
//  properly implemented taking care of month days and leap years. New
//  Date::add_day() implementation is uglier than the former, but at least it
//  operate correctly.

#include "std_lib_facilities.h"
#include "Chrono.h"

int main()
try
{

    return 0;
}
catch (Chrono::Date::Invalid& e)
{
    cerr << "Invalid Date!!\n";
    return 1;
}
catch (exception& e)
{
    cerr << e.what() << '\n';
    return 2;
}
catch (...)
{
    cerr << "Unknown exception!\n";
    return 3;
}
