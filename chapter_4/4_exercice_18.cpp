using namespace std;
#include "std_lib_facilities.h"


int main () {
    cout << "Please give a,b,c for your second degree equation and let us return you the solution(s) if any "<<endl;
    double a,b,c;
    cin >> a>> b>> c;
    double delta = b*b-4*a*c;
    
    if (delta<0){
        cout << " No solutions !";
    }
    else if (delta==0){
        cout << "Solution is x= "<<-b/(2*a) << endl;
    }
    else {
        cout << "Solutions are x =" << (-b+sqrt(delta))/(2*a)<< " and x ="<< (-b-sqrt(delta))/(2*a);
    }
    return 0; }