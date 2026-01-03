#include "std_lib_facilities.h"
# include "Ratio.h"
using Ratio::Rationnal;

int main()
try {
    Rationnal rat1 = Rationnal(5,6);
    cout <<rat1;
    Rationnal rat2 = Rationnal(10,12);
    if (rat1==rat2)cout << "equals !"<< endl;
    // testing product :
    Rationnal rat3= rat1*Rationnal(3,2);
    cout<< "product is : "<<rat3<< endl;
    // testing sum :
    cout <<  "sum is : " <<rat1+rat2 ;

    cout << "quotient is : "<< rat1/rat3;
    cout << "double conversion is : "<< rat2.conv_double()<< endl;
    //testing - 
    cout << " sub is : "<<rat1-rat1 << endl;
    return 0;

}
catch (Rationnal::Q_is_0& e)
{
    cerr << "Not a rational number !" << '\n';
    return 1;
}
catch (exception& e)
{
    cerr << e.what() << '\n';
    return 2;
}
catch (...)
{
    cerr << "Unknown exception!\n";
    return 3;
}