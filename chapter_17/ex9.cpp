#include "std_lib_facilities.h"


int main(){

    //Stack
    int i1=3;
    int i2=3;
    int i3=3;
    int i4=3;
    int i5=3;
    int i6=3;
    if (&i1 >&i6 ) cout << "Adresses go decreasing"<< endl;
    cout << &i1<<endl<< &i2  << endl<< &i3<< endl<<&i4<<endl <<&i5<< endl<<&i6<<endl<< endl;

    // free store :
    int* pi1= new int (2);
    int* pi2= new int (2);
    int* pi3= new int (2);
    int* pi4= new int (2);
    int* pi5= new int (2);
    int* pi6= new int (2);
    if (pi1 <pi6 ) cout << "dynamic free store adress goes increasing"<< endl;
    cout << pi1<<endl<< pi2<< endl<< pi3<< endl<<pi4<<endl <<pi5<< endl<<pi6<<endl<< endl;

    
    double* pd1= new double (2);
    double* pd2= new double (2);
    double* pd3= new double (2);
    double* pd4= new double (2);
    double* pd5= new double (2);
    double* pd6= new double (2);

    cout << pd1<<endl<< pd2<< endl<< pd3<< endl<<pd4<<endl <<pd5<< endl<<pd6<<endl;

    return 0;}