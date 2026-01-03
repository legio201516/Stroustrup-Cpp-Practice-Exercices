#include "std_lib_facilities.h"
#include "Chrono.h"


#ifndef MYLIB_H
#define MYLIB_H
namespace Mylib{

using Chrono::Date;
class Invalid_ISPN {};
class book_not_found {};
class user_not_found {};
class indebted_user {};

class User {
    public:
    User(string name, int card_id, double fees);
    void fee_adder(double fee_change){ fees+=fee_change;}
    //non changing functions :
    const string& get_name()const { return name;}
    const double& get_fees_owed()const { return fees;}
    private:
    string name;
    int card_id;
    double fees;
};

enum class Genre {fiction, essay, periodical,bio, youth};
class Book {
 
    public : 
    Book(string title, string author, Date copyright_date , string isbn, Genre genre);
    // modifying function members

    void check_out();
    void check_in(); 

    // non modifying function members

    const string& get_title() const{ return title;}
    const string& get_author() const { return author;}
    const string& get_ISBN() const { return isbn;}
    const Date& get_cr_date()const { return copyright_date;}
    const bool get_status()const { return status;}
    const Genre& get_genre() const{ return genre;}



    private : 

    string title;
    string author ;
    Date copyright_date;
    string isbn;
    bool status;//true if checked in;
    Genre genre;
};
class Library {
    public:
    struct Transaction{
        Book b;
        User* u;
        Date d;
    };
    Library(){}
    //Changer functions 
    void add_user(const User& u);
    void add_book(const Book& b);
    void add_transaction(const Book& b, User& u, Date d);    
    void remove_book(Book b);
    // not changing functions 
    vector<string> indebted_users();
    bool user_exists(const User& u) const;
    bool book_exists(const Book& b) const;
    private:
    vector<Book> books;
    vector<User*> users;// store users by reference, thus taking into acount modifs made to users (for debts changes) 
    vector<Transaction> transactions;

};

//helping functions :
bool operator==(const Book& a, const Book& b);
bool operator!=(const Book& a, const Book& b);
ostream& operator<<(ostream& os, const Book& d);
bool is_isbn(const std::string& isbn);
string parse_genre(const Genre& genre) ;
bool mustpay(const User& u);


} 
#endif