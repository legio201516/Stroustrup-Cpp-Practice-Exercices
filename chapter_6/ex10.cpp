using namespace std;

#include "std_lib_facilities.h"


fact(int n){
    if (n<0)error("Wrong int, no negativefact possible");
    if (n==0) return 1;
    int prod =1;
    for (int i =1; i<=n; i++){
        prod*=i;
        if (prod<1) error("factorial overflow");

    }
    return prod;
}
permutation(int a, int b){
    if (a<b || b<0)error("Wrong ints");
    return fact(a)/fact(a-b);
}
int combination(int a, int b)
{
	return permutation(a,b)/fact(b);
}
int main(){
    try{
        cout << "Please input 2 digits, a and b , and we will return you permutation P(a,b) and combiation C(a,b)"<< endl;
        int n1,n2;
        cin >> n1>>n2;
        cout << " Perm is : "<<permutation(n1,n2)<< " and combination is : "<<combination(n1,n2)<< endl;
    }
catch (runtime_error e) {
    cout << e.what() << '\n';
	keep_window_open("~");
    }
    
    return 0 ;
}