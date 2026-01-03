using namespace std;
#include "std_lib_facilities.h"


int main(){
    int r=0; int w=0;
    vector<char> answer={'a','b','c','d'};
    vector<char> guesses(4);
    cout << "Please give your guess we will tell you number of red and whites ";
    char ch1,ch2,ch3,ch4;
    cin >> ch1>> ch2 >> ch3>> ch4;
    guesses={ch1,ch2,ch3,ch4};
    vector<int> guessed(4);// vector with 0 if elem not guessed and 1 if guessed
    for (int i=0;i<4;i++){
        if (guesses[i]==answer[i]){
            guessed[i]=1;
            r+=1;
        }
    }// reds done

    for (int i=0;i<4;i++){
         for (int j =0; j<4; j++){
            if (i!=j and guessed [i]!=1 and guesses[j]==answer[i]){
                w+=1;   guessed[i]=1;
            }
         }
    }   

    cout << "reds :  "<< r<< endl<< " whites : "<< w;
    return 0 ; }