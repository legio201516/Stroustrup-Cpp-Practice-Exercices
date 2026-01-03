using namespace std;
#include "std_lib_facilities.h"

double ctok(double c ){ // celcius to kelvin
    if (c <-273.15) {error("Temperature does not exist in celsius degree");}
    double k =c +273.15;
    return k;
}
double ktoc(double k ){
    if (k <0) {error("Temperature does not exist in kelvin degree");}
    double c =k -273.15;
    return c;
}
int main(){ 
    try {
    char unit='?';
    double temp =0;
    cin >> temp>>unit;
    double converted_temp = 0;
    if (unit=='k' or unit=='K'){
        converted_temp =ktoc(temp);
        cout << converted_temp << endl;
    }
    else if (unit=='c' or unit=='C'){
        converted_temp =ctok(temp);
        cout << converted_temp << endl;
    }
    else cout << " Wrong unit, must be k or c "<< endl;
    return 0 ;}

    catch (runtime_error& e)
    {cerr << "run time error my friend : "<< e.what()<< '\n';
        keep_window_open();
        return 1 ;
    }
 } 