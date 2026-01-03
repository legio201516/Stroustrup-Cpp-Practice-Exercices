using namespace std;
#include "std_lib_facilities.h"

double ctof(double c ){ // celcius to kelvin
    if (c <-273.15) {error("Temperature does not exist ");}
    double f =c*9.0/5 +32;
    int int_f= f;
    if (f !=int_f) {error("Oops, the result is not an int");}

    return f;
}
double ftoc(double f ){
    double c =(f-32)*5.0/9;
    int int_c= c;
    if (c !=int_c) {error("Oops, the result is not an int");}
    if (c <-273.15) {error("Temperature does not exist");}

    return c;
}
int main(){ 
    try {
    char unit='?';
    double temp =0;
    cin >> temp>>unit;
    double converted_temp = 0;
    if (unit=='f' or unit=='F'){
        converted_temp =ftoc(temp);
        cout << converted_temp << endl;

    }
    else if (unit=='c' or unit=='C'){
        converted_temp =ctof(temp);
        cout << converted_temp << endl;
    }
    else cout << " Wrong unit, must be f or c "<< endl;
    return 0 ;}

    catch (runtime_error& e)
    {cerr << "run time error my friend : "<< e.what()<< '\n';
        keep_window_open();
        return 1 ;
    }
 } 