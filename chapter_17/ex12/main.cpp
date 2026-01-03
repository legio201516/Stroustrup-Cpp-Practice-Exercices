#include "Link.h"



void print_all(Link* p)
{
    cout << "{ " ;
    while (p){
    God g = p->getGod();
    cout << p->value<< " Attributes : "<< g.name
    <<'\t'<< g.mythology<< '\t'<< g.vehicle<< '\t'<< g.weapon<< endl;
    p=p->next();
    if (p) cout << " , ";
        }
    cout << " }"<< endl;
}
int main(){
    // Build gods :
    God g1= God();

    //build list :
    Link* norse_gods = new Link(g1,"Thor");
    norse_gods = norse_gods->insert(new Link(g1,"Odin"));
    norse_gods = norse_gods->insert(new Link(g1,"Zeus"));
    norse_gods = norse_gods->insert(new Link(g1,"freia"));
    Link* greek_gods = new Link(g1,"Hera");
    greek_gods = greek_gods->insert(new Link(g1,"Athena"));
    greek_gods = greek_gods->insert(new Link(g1,"Mars"));
    greek_gods = greek_gods->insert(new Link(g1,"Poseidon"));
    
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