using namespace std;
#include "std_lib_facilities.h"


is_name(string s){
    if (s=="birds" or s=="c++" or s=="fish"){
        return true;
    }
    return false;
}
is_verb(string s){
    if (s=="fly" or s=="swim" or s=="rules"){
        return true;
    }
    return false;
}
is_conj(string s){
    if (s=="or" or s=="but" or s=="and"){
        return true;
    }
    return false;
}


int main(){
    string ok ="ok";
    string punctuation= "ok";
    string s= "error";
    string previous ="previous";
    cin >>previous;
    while (cin >> s){


        if (!is_verb(s) and !is_name(s) and !is_conj(s)and s!="The" and s!="the" and s!="."){
            ok = "Pas ok ";
            cout<< ok <<s<< " not a word";
            break;
        }

        if ((previous =="The" and !is_name(s)) 
         or (is_name(previous) and !is_verb(s)) 
         or (is_verb(previous) and !is_conj(s)) 
         or (is_conj(previous) and s!="the" and !is_name(s) ))
        ok = "Pas ok ";    
        if (previous == "." ) {
            cout << "punctuation wring ";
            punctuation = "Pas ok"; break;}

        previous=s;
        }


            

    if (ok=="ok" and punctuation =="ok")cout <<ok;
    else cout << "pas ok";
    return 0;
}