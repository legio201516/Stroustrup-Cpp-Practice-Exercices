#include "std_lib_facilities.h"

char* to_lower(char* p){// we take a c style string and modify it
    for (int i; p[i];i++){
        if ('A'<=p[i] && p[i]<='Z') p[i]-= ('A'-'a');
    }
    return p;
}
void test(const string& ss)	// rely on visual inspection
{
	string s = ss;	// take a copy to avoid modifying original
	cout << s << '\n';
	char* p = &s[0];	
	to_lower(p);// we do lower() of the first char*
	cout << p << '\n';
}

int main(){
    char s[] = "AAAADdoibBiubszHZJ";
    test(s);
    return 0;  

}