#include "std_lib_facilities.h"


// We want to guess the size of an int, double, and bool using pointers adresses.
// &p[1] gives the adress of the pointer itself
// reinterpret_cast<char*>(&p[1]) gives this adress in bytes.
int  print_pi_adress(int){
    int* p = new int [2];
    int i = reinterpret_cast<char*>(&p[1]) - reinterpret_cast<char*>(&p[0]);
    return i; 
}
int  print_pd_adress(double){
    double* p = new double [2];
    int i = reinterpret_cast<char*>(&p[1]) - reinterpret_cast<char*>(&p[0]);
    return i;
}
int print_bool_adress(bool){
    bool* p = new bool [2];
    int i = reinterpret_cast<char*>(&p[1]) - reinterpret_cast<char*>(&p[0]);
    return i;

}
int main(){
    // ints
    int i1= 9;
    cout <<print_pi_adress(i1)<< endl;
    // doubles
    double d1= 9.22;
    cout << print_pd_adress(d1)<< endl;

    // bools
    bool b1= true;
    cout << print_bool_adress(b1)<< endl;
    
    return 0;
}