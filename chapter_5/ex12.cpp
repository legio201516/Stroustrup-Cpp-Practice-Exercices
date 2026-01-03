using namespace std;
#include "std_lib_facilities.h"


int main(){
    vector<int> answer={2,3,4,5};
    vector<int> v;
    cout << "Please give your guess we will tell you number of red and whites ";
    int a,b,c,d;
    cin >> a>> b >> c>> d;
    v.push_back(a);
    v.push_back(b);
    v.push_back(c);
    v.push_back(d);
    vector<int> r(4,0);// number of reds and whites
    vector<int> w(4,0);
    for (int i=0; i<answer.size(); i++){
        for(int j=0; j<answer.size(); j++){
            if (i==j and v[i]==answer[j]) { r[i]=1;}
            else if (v[i]==answer[j] and w[i]!=1){ w[i]=1 ; 
        }
    }}
    cout << "reds :  "<< r[0]+r[1]+r[2]+r[3]<< endl<< " whites : "<< w[0]+w[1]+w[2]+w[3];
    return 0 ; }