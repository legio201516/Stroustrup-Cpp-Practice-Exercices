#include "std_lib_facilities.h"
ostream& print_array(ostream& os, int* a, int n){//prints values of a with n elements assumed
    for (int i =0;i<n;i++){
        os << a[i]<< endl;
    }
    return os;
} 

int main(){

    int i1=7;
    int* p1= &i1;
    cout << "pointeur value : "<< p1 << " pointed int value : "<< *p1<< endl;
    //
	int sevenInts [7] = { 1,2,4,8,16,32,64 };
    int* p2=&sevenInts[0];
    cout << "pointeur value : "<< p2 << " pointed int value : "<< *p2<< endl;
    print_array(cout, p2, 7);
    // 
    int* p3=p2;
    p2=p1;
    p2=p3;
    cout << "pointeur p1 value : "<< p1 << " pointed int value : "<< *p1<< endl;
    cout << "pointeur p2 value : "<< p2 << " pointed int value : "<< *p2<< endl;
    // 
    int tenInts [10] = { 1,2,4,8,16,32,64, 128, 256, 512 };
    p1=tenInts;
    cout << "pointeur p1 value : "<< p1 << " pointed int value : "<< *p1<< endl;
    int tenInts2 [10];
    p2 = tenInts2;
    for (int i = 0; i<10; i++){
        p2[i]=p1[i];
    }
    print_array(cout, p2, 10);
    // Now with VECTORS
    vector<int> v1{1,2,4,8,16,32,64, 128, 256, 512 };
    p1=&v1[0];
    vector<int> v2(10);
    p2= &v2[0];
    for (int i = 0; i<10; i++){
        p2[i]=p1[i];
    }
    return 0;}