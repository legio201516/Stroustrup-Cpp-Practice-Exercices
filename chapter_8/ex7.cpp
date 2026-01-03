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
    cout << "Please enter names of 8 people and quit with | : "<<endl;
    string s;
    vector<string> name;
    while (cin >>s and name.size()<8){
        name.push_back(s);
    }
    cout << "Please enter ages of people and quit with '| '"<<endl;
    print("Names :\n", name);
    int n = name.size();
    vector<double> ages;
    double d = 0;
    while (cin>>d and (ages.size()<n)){ 
        cout << d<<endl;
        ages.push_back(d);
        }// get their ages.

    cout << "Unsorted pairs :"<< endl;
    for (int i = 0; i<n; i++){
        cout << name[i]<<",  "<< ages[i]<<endl;
    }
    vector<string> copy_names = name;//old names order
    sort(name.begin(), name.end());

    vector<int> sorted_ages(n);// let's make a sorted age vector
    for (int i = 0;i<n; i++){
        string current_name = copy_names[i];
        double current_age = ages[i];
        for (int j = 0;j<n; j++){
            if (name[j]==current_name) { // we look for the name's new index j in the sorted name list
                int new_index = j;
                sorted_ages[new_index]=current_age;}
        }
    }
    
    cout << " Sorted pairs : \n";
    for (int i = 0; i<n; i++){
        cout << name[i]<<",  "<< sorted_ages[i]<<endl;
    }    return 0;
}