using namespace std;
#include "std_lib_facilities.h"

int main () {
    int current_spot=1;
    int sum=1;
    int current_grains=1;
    bool found1=false;
    bool found2=false;
    bool found3=false;


    while ((found1==false or found2==false or found3 == false ) and current_spot<75){
        // On calcule les grains avec la nouvelle case, la sum etc
        current_grains*=2;
        sum+=current_grains;
        current_spot++;
        // 
        if (sum >= 1000 and found1 == false){
            cout << current_spot << " cases sont assez pour 1000 grains de riz car en donnent : "<<sum<< endl;
            found1=true;}
        if (sum >= 1000000 and found2 == false){
            cout << current_spot << " cases sont assez pour 1000000 grains de riz car en donnent : "<<sum<< endl;
            found2=true;}

        if (sum >= 1000000000 and found3 == false){
            cout << current_spot << " cases sont assez pour 1000000000 grains de riz car en donnent : "<<sum<< endl;
            found3 = true;}// fin du programme
    }
    return 0;}