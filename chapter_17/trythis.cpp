#include "std_lib_facilities.h"

int main(){
    cout << "the size of char is "<< sizeof(char)<< " or  " <<sizeof('a') << endl;
    cout << "the size of int  is "<< sizeof(int )<< " or  " <<sizeof(8)  << endl;
    cout << "the size of double  is "<< sizeof(double )<< " or  " <<sizeof(0.558)  << endl;
    cout << "the size of bool  is "<< sizeof(bool )<< " or  " <<sizeof(true)  << endl;
    cout << "the size of long int  is "<< sizeof(long int )<< " or  " <<sizeof(long int)  << endl;
    cout << "the size of string  is "<< sizeof(string)<< " or  " <<sizeof("isvzidubz")  << endl;

    return 0;
}