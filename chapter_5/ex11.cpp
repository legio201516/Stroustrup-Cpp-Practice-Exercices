using namespace std;
#include "std_lib_facilities.h"


int main(){
    int lastlast=1;
    int last=1;
    int current=0;
    int index=0;
    while (index <1000000 and current >=0){
        current=last+lastlast;
        
        cout << current<< endl;
        lastlast=last;
        last = current;
        index++;
    }
return 0;}