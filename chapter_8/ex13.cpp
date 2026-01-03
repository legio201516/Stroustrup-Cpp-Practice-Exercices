#include "std_lib_facilities.h"


void print_until_s(vector<string> v, string quit){

    for (int i = 0; i<v.size(); i++){
        if (v[i]==quit) return;
        cout << v[i]<< endl;
    }
    
}
void print_until_ss(vector<string> v, string quit){
    bool seen = false;
    for (string s: v){
        if (s==quit){
            if (seen) return;
            seen = true;
        }  
      cout << s<< endl;

}
    
}


int main()
try {
    print_until_ss({"stop","qud","doein","dejn", "iub", "stop", "uion"}, "stop");

    return 0;
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    return 1;
}
catch(...)
{
    cerr << "Unknown exception!!\n";
    return 2;
}