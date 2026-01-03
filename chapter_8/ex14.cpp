#include "std_lib_facilities.h"

void print(const vector<int>& v , string label){
    cout << label << endl;
    for (int i : v){
        cout << i<< '\t';
    }
}


vector<int> lenght_counter(vector<string> v){
    vector<int> sizes;
    for (string s : v){
        sizes.push_back(s.size());
    }

    return sizes;
}
string longest(vector<string> v){
    string longest= "";
    for (string s : v){
        if(s.size()>longest.size()) longest = s;
    }

    return longest;
}
string shortest(vector<string> v){
    string shortest= v[0];
    for (string s : v){
        if(s.size()<shortest.size()) shortest = s;
    }

    return shortest;
}
string first(vector<string> v){
    string first= v[0];
    for (string s : v){
        if(s<first) first = s;
    }

    return first;
}
string last(vector<string> v){
    string last= v[0];
    for (string s : v){
        if(s>last) last = s;
    }

    return last;
}
int main()
    try{
    vector<string> v = {"deibu", "doeu","ss", "ziyb", "siuzbd"};
    print(lenght_counter(v), "try");
    cout << longest(v)<< endl;
    cout << shortest(v)<< endl;
    cout << first(v)<< endl;
    cout << last(v)<< endl;

    return 0;

    
}
catch(exception& e)
{
    cerr << e.what() << '\n';
    return 1;
}
catch(...)
{
    cerr << "Unknown exception!!\n";
    return 2;
}