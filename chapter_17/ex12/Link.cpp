#include "Link.h"

Link* Link:: insert(Link* n)
{
    // inserts n before this object; returns n
    if (n==0) return this;
    if (this==0) return n;
    n->succ = this; // this object comes after n
    if (prev) prev->succ = n;
    n->prev = prev; // this object's predecessor becomes n's predecessor
    prev = n; // n becomes this object's predecessor
    return n; 
}
Link* Link:: add(Link* n)
{
    // adds n ater this object; returns n. REMARK : could be done in 2 lines by succ-> insert(n)
    if (n==0) return this;
    if (this==0) return n;
    n->prev = this; // this object comes after n
    if (succ) succ->prev = n;
    n->succ = succ; // this object's predecessor becomes n's predecessor
    succ = n; // n becomes this object's predecessor
    return n; 
}
Link* Link::find(const  string& s)// finds s occ in list, returns  Link associated and 0 if not inside
{   Link* p = this;
    while(p){
        if (p->value ==s)return p;
        p=p->succ;
    }
    return 0;
}
Link* Link:: erase()// erases and return succ
{   
    if (this ==0) return 0;
    if (prev)prev-> succ=succ;
    if (succ)succ-> prev=prev;
    return succ;
}