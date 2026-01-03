# include "monnaieex15.h"
using namespace monney;
using monney::Monnaie;

int main()try{
    Monnaie purse1=Monnaie(1,23,Currency::EUR);
    cout << purse1;
    //testing multiplication and rounding
    double d = 1.2;
    Monnaie purse2 = purse1*d;
    cout <<"Rounded cents for 1.2 mult : "<< purse2.get_cents()<< endl;
    //testing addition : 
    Monnaie purse3 = purse1+purse2;
    cout <<"Added cents of previous results : "<< purse3.get_cents()<< endl;

    // testing >> :
    cout << "Write some quantities (examples: $123.04 or $-10.10, two digits"
    << " for cents are mandatory. Quit with Ctrl+Z).\n> ";
    Monnaie input{0};
    while (cin) {
        cin >> input;
        if (cin.eof()) break;
        if (cin.fail()) {
            cout << "Bad input format\n> ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }}

    
    
    return 0;}
catch(Monnaie::non_valid_money& e)
{
    cerr << "Non valid money \n";
    return 1;
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    return 2;
}
catch(...)
{
    cerr << "Unknown exception!!\n";
    return 3;
}

