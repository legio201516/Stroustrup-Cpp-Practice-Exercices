#include "std_lib_facilities.h"
void print(string s, vector<string> v){
    cout << s<<endl;
    for (int i =0; i<v.size(); i++){
        cout <<v[i]<< '\t';
    }
}
vector<string> list_swap1(vector<string> v){
    int n=v.size();
    vector<string> v2;

    for (int i = 0; i<n; i++){
        v2.push_back(v[n-1-i]);
    }
    
    return v2;

}

vector<string> list_swap2(vector<string>& v){
    int n=v.size();
  
            for(int i =0; i <=n/2; i++){
                swap(v[i],v[n-1-i]);
            }
    
    return v;
    
}

int main(){
    vector<string>v1 = {" de "," ste "," agathe "};
    print(" list swap with copy",list_swap1(v1));
    vector<string>v2 = {" de "," ste "," agathe "};
    list_swap2(v2);
    print(" list swap with reference",v2);

    return 0;
}