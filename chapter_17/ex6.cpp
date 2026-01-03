#include "std_lib_facilities.h"


int main(){
    long int bytes_couter=0;
    while (true){
        double* p= new double[10000000];
        bytes_couter+=sizeof(*p)*10000000;
        cout << bytes_couter<<'\t';
    }
    return 0;
}