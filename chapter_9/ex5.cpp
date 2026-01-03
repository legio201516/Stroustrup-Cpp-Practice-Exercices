#include "ex5mylib.h"
#include "std_lib_facilities.h"
#include "Chrono.h"

using Chrono::Date;
using Mylib::User;
using Mylib::Book;
using Chrono::Month;
using Mylib::Genre;
using Mylib::Library;

int main()
try
{
     // Test Mylib::is_isbn() function
    string s;
    string isbnn{};
    // test isbn checking function
    isbnn = "342-2342-2344-A";
    s = Mylib::is_isbn(isbnn) ? "" : "not ";
    cout << isbnn << " is " << s << "a valid ISBN\n";
    isbnn = "23-6502-656-7";
    s = Mylib::is_isbn(isbnn) ? "" : "not ";
    cout << isbnn << " is " << s << "a valid ISBN\n";
    // Test Date class : ex 5 and 6
    Date date1 = Date(1999,Month::jan,3) ;
    Book mybook = Book("cpp principles", "bjarne", date1 ,isbnn , Genre::youth);
    Book mybook2 = Book("cool water", "Paul", date1 ,"342-2342-2344-A" , Genre::youth);
    cout<<mybook.get_cr_date() << '\t'<< mybook.get_ISBN()<< endl;
    if (mybook!=mybook2 )cout << "nice" << endl;
    cout<< mybook;

// test the User class ex 8 
    User myuser = User("Paul",1406, 10 ) ;
    cout << myuser.get_fees_owed();
    User myuser2 = User("Jeanne",00026, 100 );

// test the Library class ex 9
    Library mylib1= Library();
    mylib1.add_book(mybook);
    mylib1.add_user(myuser);
    mylib1.add_user(myuser2);
    cout << "Debted users : "<<mylib1.indebted_users()[0]<< mylib1.indebted_users()[1]<<endl;
    myuser.fee_adder(-10);
    cout << myuser.get_fees_owed()<< endl;
    //cout << "Debted users after change: "<<mylib1.indebted_users()[0]<< mylib1.indebted_users()[1]<< endl;
    //mylib1.add_transaction(mybook, myuser, date1);
    return 0;

}

.
catch(Mylib::indebted_user& e)
{
    cerr << "debted user !\n";
    return 1;
}
catch(Mylib::user_not_found& e)
{
    cerr << " user not found !\n";
    return 1;
}
catch(Mylib::book_not_found& e)
{
    cerr << " Book not found !\n";
    return 1;
}
catch(Chrono::Date::Invalid& e)
{
    cerr << "Invalid date!\n";
    return 1;
}
catch(Mylib::Invalid_ISPN& e)
{
    cerr << "Invalid Ispn!\n";
    return 1;
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    return 2;
}
catch(...)
{
    cerr << "Unknown exception!\n";
    return 3;
}

