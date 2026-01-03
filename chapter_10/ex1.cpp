#include "std_lib_facilities.h"


int main(){
    string name="ex1.txt";
   
    ifstream ist(name.c_str());
    if (!ist) error("Can't open output file", name);
    int i;
    int s = 0;
    while (ist>>i){
        s+=i;
    }
    cout << s;
    return 0;
}