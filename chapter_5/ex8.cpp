using namespace std;
#include "std_lib_facilities.h"


int main(){ 
    try {
    int n =0;
    cout << "Please give an N."<< endl;
    cin >> n; 
    cout << "Now give integers, we will give you the sum of the N first ints"<< endl;
    int elem= 0 ; 
    int sum=0;
    vector<int> v;
    while (cin >> elem){
        v.push_back(elem);
    }
    
    for (int i =0; i< n; i++){
        sum+=v[i];
    }
    cout << "Sum of N first elems is : "<< sum << endl;
    return 0 ;}

    catch (Range_error& e)
    {cerr << "range error my friend : "<< e.what()<< '\n';
        keep_window_open();
        return 1 ;
    }
 } 