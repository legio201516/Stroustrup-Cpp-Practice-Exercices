#include "std_lib_facilities.h"

char* strdup(const char* s){
    int lenght =0;
    while (s[lenght]!=0){
        lenght++;
    }
    char* p =new char[lenght+1];
    for (int i=0; i<=lenght;i++){

	    p[i] = s[i];
        cout << p[i]<< endl;	
    }
    
    return p;
}
int main(){
    char hello[] = "hello, world";
    strdup(hello);
    return 0;
}