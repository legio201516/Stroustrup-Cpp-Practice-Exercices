using namespace std;
#include "std_lib_facilities.h"

int main () {
    cout << " Give 2 numbers followed by an operator (+-*/) : "<<endl;
    double d1,d2;

    char op;

    while (cin >> d1>>d2>>op){
        switch (op){
            case '+':
                    cout << "La somme de " << d1<< " et de "<< d2<< " est "<< d1+d2 << endl;
                    break;
            case '-':
                cout << "La soustraction de " << d1<< " et de "<< d2<< " est "<< d1-d2 << endl;
                        break;

            case '/':
                cout << "La division de " << d1<< " par "<< d2<< " est "<< d1/d2 << endl;
                     break;

            case '*':
                cout << "La multiplication de " << d1<< " par "<< d2<< " est "<< d1*d2 << endl;
                        break;
                                             
            default:
            cout << "Op not supported ";
                                break;

        }

    }
    return 0;}