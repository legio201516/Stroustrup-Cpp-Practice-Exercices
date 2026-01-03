using namespace std;
#include "std_lib_facilities.h"


int area(int length, int width){
    if (length<=0||width<=0) error("area() pre condition");
    int a =length*width;
    cout << " a is in area : "<< a << endl;
    if (a<=0) error("area() post condition");
    return a;
}
int main(){
    int m,n;
    cin >> m >> n ;
    cout << m << "  " <<n<< endl;
    cout<< area(m,n)<< endl;
    
    return 0 ;
}