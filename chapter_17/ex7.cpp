#include "std_lib_facilities.h"


int main(){
    char ch='a';
    char* p= new char [300];
    int i = 0;
    while(ch!='!'){
        cin>> ch;
        p[i]=ch;
        i++;
    }
    cout <<endl<< p<< endl;
    return 0;}
    