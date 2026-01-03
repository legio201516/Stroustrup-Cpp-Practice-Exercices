using namespace std;
#include "std_lib_facilities.h"

int power10(int n){
    int res=1;
    for (int i =0; i<n; i++){
        res*=10;
    }
    return res;
}
int main(){
    char ch;
    vector<int> v;
    int num=0;
    while(cin >> ch){  
        if (ch<'0'|| ch>'9')break;
        int n=ch-'0';
        v.push_back(n);
        if (v.size()==4) break;
        }
    
    int n=v.size();
    for (int i=0; i<n; i++){
        num+=v[i]*power10(n-1-i);
    }
    switch (n){
    case 1 : 
    cout << num << " equivaut a "<< v[0]<<" unites.";break;
    case 2 : 
    cout << num << " equivaut a "<<v[0] <<" dizaines, "<< v[1]<<" unites.";break;
    case 3 : 
    cout << num << " equivaut a "<< v[0]<<" centaines, "<< v[1]<<" dizaines, "<< v[2]<<" unites.";break;
    case 4 : 
    cout << num << " equivaut a "<<v[0]<< " milliers, "<< v[1]<<" centaines, "<< v[2]<<" dizaines, "<< v[3]<<" unites.";break;
    default : 
    error("wrong input");
    }


    return 0;
}
