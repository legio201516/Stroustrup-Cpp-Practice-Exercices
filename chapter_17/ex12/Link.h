#include "std_lib_facilities.h"
struct God{
	God()
	{}
	God(string n, string m, string v, string w)
		: name(n)
		, mythology(m)
		, vehicle(v)
		, weapon(w)
	{}
    string name,mythology,vehicle, weapon;
   
};

class Link {
    public:
    string value;
    Link(God g,const string& v, Link* p = 0, Link* s = 0)
    : god(g), value(v), prev(p), succ(s) { }
    Link* insert(Link* n) ; // insert n before this object
    Link* add(Link* n) ; // insert n after this object
    Link* erase() ; // remove this object from list
    Link* find(const string& s); // find s in list
    const Link* find(const string& s) const; // find s in list
    Link* advance(int n) const; // move n positions in list
    Link* next() const { return succ; }
    Link* previous() const { return prev; }
    God getGod(){ return god;}
    private:
    God god;
    Link* prev;
    Link* succ;
};