#include "Link.h"



void print_all(Link* p)
{
    cout << "{ " ;
    while (p){
    cout << p->value;
    if (p=p->next()) cout << " , ";
        }
    cout << " }";
}
int main(){
    //build list :
    Link* norse_gods = new Link("Thor");
    norse_gods = norse_gods->insert(new Link("Odin"));
    norse_gods = norse_gods->insert(new Link("Zeus"));
    norse_gods = norse_gods->insert(new Link("freia"));
    Link* greek_gods = new Link("Hera");
    greek_gods = greek_gods->insert(new Link("Athena"));
    greek_gods = greek_gods->insert(new Link("Mars"));
    greek_gods = greek_gods->insert(new Link("Poseidon"));
    
    //correct mistake :
    Link* p = greek_gods->find("Mars");
    if (p){ p->value = "Ares";}


    print_all(norse_gods);
    cout<<"\n";
    print_all(greek_gods);
    cout<<"\n";
    Link* p2 = norse_gods->find("Zeus");
    if (p2) {
    if (p2==norse_gods) norse_gods = p2->next();
    p2->erase();
    greek_gods = greek_gods->insert(p2);
    }
    
    print_all(norse_gods);
    cout<<"\n";
    print_all(greek_gods);
    return 0;
}