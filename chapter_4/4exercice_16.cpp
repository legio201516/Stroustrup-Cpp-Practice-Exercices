using namespace std;
#include "std_lib_facilities.h"


int main () {
    cout << "Please give a suite of ints, and let us return you the mode of it. "<<endl;
    vector<int> values;
    vector<int> unique_values;// The idea is to have a vector that has elements corresponding to frenquencies.
    vector<int> times;// frequencies

    int i;
    while (cin >> i){
        values.push_back(i);
    }


    sort( values.begin(),values.end());
    unique_values.push_back(values[0]);
    times.push_back(1);
    for (int i =1;i<values.size();i++){
         if (values[i]==values[i-1]){// we increment of 1 the frequency of the current value in our (unique) times vector
            times[times.size()-1]++;
         }else {
            unique_values.push_back(values[i]);// We encountered a new item in values
            times.push_back(1);}
            }

    int max_freq=0;
    int mode=0;
    for (int i =0; i<unique_values.size();i++){
        if (times[i]>max_freq)  {
            max_freq=times[i];
            mode=unique_values[i];
        }

    }

    cout << "Most frequent is : "<<mode << endl;

    return 0;}
