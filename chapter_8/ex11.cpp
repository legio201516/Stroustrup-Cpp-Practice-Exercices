//  Write a function maxv() that returns the largest element of a vector.

#include "std_lib_facilities.h"

void print(const string& label, const vector<double>& data)
// Only read arguments, so it safe to pass them by const-reference
{
    cout << label << ": { ";
    for (double d : data)
        cout << d << ' ';
    cout << "}\n";
}

double maxv(const vector<double>& v){
    double max = v [0];
    for (int i = 0; i<v.size(); i++){
        if (v[i]>max) max = v[i];
    }
    return max; 
}
    
int main()
try {
    vector<double> test_data{-5, 0, 6.7, -1000, 10.1e5, 10e5};

    print("Test data", test_data);
    cout << "Largest element from data:  " << maxv(test_data) << '\n';
    
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
