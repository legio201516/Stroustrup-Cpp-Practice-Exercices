#include "std_lib_facilities.h"

void print(string s, vector<int> v){
    cout << s<<endl;
    for (int i =0; i<v.size(); i++){
        cout <<v[i]<< '\t';
    }
}
vector<int> fibonacci(int x, int y, vector<int> v, int n){
    if (v.size()!=0) error("not empty vector in fibonacci entry");
    v.push_back(x);
    v.push_back(y);
    for (int i =0; i< n-2; i++){
        v.push_back(v[i]+v[i+1]);
    }
    return v;
}
int main(){
    //print("fibonacci ! ",fibonacci(1,2,{}, 100));
    return 0;
}