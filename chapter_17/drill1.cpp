#include "std_lib_facilities.h"

ostream& print_array10(ostream& os, int* a){//prints values of a with 10 elements assumed
    for (int i =0;i<10;i++){
        os << a[i]<< endl;
    }
    return os;
}
ostream& print_array(ostream& os, int* a, int n){//prints values of a with n elements assumed
    for (int i =0;i<n;i++){
        os << a[i]<< endl;
    }
    return os;
}
ostream& print_vector(ostream& os, vector<int> v, int n){//prints values of vector v with n elements assumed
        for (int i =0;i<n;i++){
        os << v[i]<< endl;
    }    return os;

}
int main(){
    // using new
    double* table=new double[10];
    for (int i =0;i<10;i++){
        cout << table[i]<< endl;
    }
    delete[] table;
    // 
    int* itable = new int[10];
    for (int i = 0;i<10; i++){
        itable[i]=i+100;
    }
    print_array10(cout, itable);
    delete[] itable;
    //
    int* iitable = new int[11];
    for (int i = 0;i<11; i++){
        iitable[i]=i+100;
    }
    print_array(cout, iitable, 11);
    delete[] iitable;

    //
    int* iiitable = new int[20];
    for (int i = 0;i<20; i++){
        iiitable[i]=i+100;
    }
    print_array(cout, iiitable, 20);
    delete[] iiitable;
    // using vector
    cout << "Vector drills :"<< endl;
    vector<int> v1(20);
    for (int i = 0;i<20; i++){
        v1[i]=i+100;
    }
    print_vector(cout, v1, 20);
    
    return 0;}