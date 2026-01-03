#include "std_lib_facilities.h"


int main(){
    char* cstr=new char[20];
	cin.get(cstr, 20, '!');// this get function seems to stop and quit if we reach its limit

    return 0;}
