#include "std_lib_facilities.h"
void print(string s, vector<int> v){
    cout << s<<endl;
    for (int i =0; i<v.size(); i++){
        cout <<v[i]<< '\t';
    }
}
vector<int> list_swap1(vector<int> v){
    int n=v.size();
    vector<int> v2;

    for (int i = 0; i<n; i++){
        v2.push_back(v[n-1-i]);
    }
    
    return v2;

}

vector<int> list_swap2(vector<int>& v){
    int n=v.size();
  
            for(int i =0; i <=n/2; i++){
                swap(v[i],v[n-1-i]);
            }
    
    return v;
    
}

int main(){
    vector<int>v1 = {1,2,3,4,5};
    print(" list swap with copy",list_swap1(v1));
    vector<int>v2 = {1,2,3,4,5};
    list_swap2(v2);
    print(" list swap with reference",v2);

    return 0;
}