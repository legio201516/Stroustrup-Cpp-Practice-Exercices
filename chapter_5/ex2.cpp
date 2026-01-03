using namespace std;
#include "std_lib_facilities.h"

double ctok(double c ){ // celcius to kelvin
    if (c <-273.15) {error("Temperature does not exist in celsius degree");}
    double k =c +273.15;
    return k;
}
int main(){
    try {
    double c =0;
    cin >> c;
    double k = ctok(c);
    cout << k << endl;
    return 0 ;}

    catch (runtime_error& e)
    {cerr << "run time error my friend : "<< e.what()<< '\n';
        keep_window_open();
        return 1 ;
    }
 } 