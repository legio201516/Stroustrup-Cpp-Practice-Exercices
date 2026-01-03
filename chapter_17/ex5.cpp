#include "std_lib_facilities.h"

char* findx(const char* s, const char* x){// finds first occ of x in s
    int index = 0;
    while (s[index]!=0){
        cout << "hll";  
        if (s[index]==x[0]){// we might get all the x string, 
            //lets start a new index and a new loop on x
            int index2=0;
            bool equal=false;
            while (s[index+index2]== x[index2]){// loop on x
                cout << " x=s on index : "<<index+index2<< x[index2]<< endl;
                index2++;
                if (x[index2]==0) {
                    equal=true;cout << " arrived at end of x ! "<< endl;
                    }
                }
            char* first_occ = const_cast<char*>(&s[index]);
            if (equal) return first_occ;
            }
        index++;
        }
    error("x not found"); 
}
       


int main(){
    char hello[] = "hello, world";
    char he[] = "lo, w";

    char * s = findx(hello,he );
    cout <<"char is : " << s;
    return 0;
}