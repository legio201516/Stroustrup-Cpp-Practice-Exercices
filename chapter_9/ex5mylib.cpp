#include "ex5mylib.h"
#include "std_lib_facilities.h"
#include "Chrono.h"
namespace Mylib{

Book::Book(string titlee, string authorr, Date copyright_datee , string isbnn, Genre genree )
:title(titlee),  author(authorr),  copyright_date(copyright_datee) ,  isbn(isbnn), genre(genree)
{
    if (!is_isbn(isbnn)) throw Invalid_ISPN();
}
bool is_isbn( const string& isbn)
{   vector<int> dash_indexes;
    // let's first look for the dashes indexes
    for (int i =0; i<isbn.size(); i++){
        if (isbn[i]=='-') dash_indexes.push_back(i);
    }
    if (dash_indexes.size()!=3) return false;
    //Now let's check everything before third dash is int;
    char ch;
    for (int i = 0; i<dash_indexes[2]; i++){
        ch = isbn[i];
        if(!isdigit(ch)&& ch!='-')return false;
    }
    //Now let's check the last char is a letter of digit;
    char last= isbn[isbn.size()-1];
    if (!isdigit(last) and !isalpha(last)) return false;
    return true;
}


void Book::check_in()
{
    if (get_status()) error(" This book is already checked in");
    status=true;
}
void Book::check_out()
{
    if (!get_status()) error(" This book is already checked out");
    status=false;
}
bool operator==(const Book& a, const Book& b)
{
    if (a.get_ISBN()!=b.get_ISBN()) return false;
    return true;
}
bool operator!=(const Book& a, const Book& b)
{
    if (a==b) return false;
    return true;
}
ostream& operator<<(ostream& os, const Book& d)
{
    return os << d.get_title()<< endl<< d.get_author()<< endl<< d.get_ISBN()<<endl<<parse_genre(d.get_genre())<<endl;
}

string parse_genre(const Genre& genre) {

    switch (genre) {
        case Genre::fiction:
            return "Fiction";
        case Genre::periodical:
            return "Periodical";
        case Genre::bio:
            return "Biography";
        case Genre::youth:
            return "Children";
        case Genre::essay:
            return "Essay";
        default:
            return "Unknown genre";
    }
}
User::User(string name, int card_id, double fees)
    : name(name), card_id(card_id), fees(fees)
{
}




// ---- Helper: mustpay ----
bool mustpay(const User& u) {
    cout << "Checking fees for user " << u.get_name()
              << ": " << u.get_fees_owed() << endl;
    return (u.get_fees_owed() > 0);
}

// ---- Add user ----
void Library::add_user(const User& u) {
    users.push_back(const_cast<User*>(&u)); // store as pointer to non-const
}

// ---- Add book ----
void Library::add_book(const Book& b) {
    books.push_back(b);
}

// ---- Check existence ----
bool Library::user_exists(const User& u) const {
    for (User* ptr : users)
        if (ptr->get_name() == u.get_name())
            return true;
    return false;
}

bool Library::book_exists(const Book& b) const {
    for (const Book& stored : books)
        if (stored == b)
            return true;
    return false;
}

// ---- Add transaction ----
void Library::add_transaction(const Book& b, User& u, Date d) {
    if (mustpay(u)) throw indebted_user();
    if (!user_exists(u)) throw user_not_found();
    if (!book_exists(b)) throw book_not_found();

    transactions.push_back(Transaction{ b, &u, d });
}

// ---- Indebted Users ----
vector<string> Library::indebted_users() {
    vector<string> list;

    for (User* u : users) {
        if (mustpay(*u)) {
            list.push_back(u->get_name());
            cout << "Added to indebted list: " << u->get_name() << endl;
        }
    }
    return list;
}


}