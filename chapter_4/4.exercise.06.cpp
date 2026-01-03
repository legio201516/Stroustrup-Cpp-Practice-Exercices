using namespace std;
#include "std_lib_facilities.h"

const vector<string> names{"zero","one","two","three","four","five","six","seven","eight","nine"};



int int_finder(string s){
    for (int i =0; i<=names.size();i++){
        if (names[i]==s){
            return i;
        }
    }return -1;        

    }



int main () {
    bool control = true;
    cout << "Please insert digit (like '4') or letter-number(like 'one'), or '|' to quit "<< endl;
    int number ;
    string int_name;
    while(control){
        if (cin>> number){
             cout << " Here is your name of int "<< names[number]<< endl;
        }
        else {
            cin.clear();
            cin>> int_name;
            if (int_name=="|"){
                control=false;
            }
            else cout << " Here is your int of name "<< int_finder(int_name)<< endl;
        }
    }


    return 0;}
