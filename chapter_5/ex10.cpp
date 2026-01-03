using namespace std;
#include "std_lib_facilities.h"


int main()
    try {
    int n =0;
    cout << "Please give an N."<< endl;
    cin >> n; 
    cout << "Now give doubles, we will give you the sum of the N first doubles"<< endl;
    double elem= 0 ; 
    vector<double> v_elem;
    vector<double> v_dists;
    int index=0;
    while (cin >> elem){
        v_elem.push_back(elem);
        }
    if(n > v_elem.size() or v_elem.size()==0) error("Hey, input more numbers  !");
    double sum=v_elem[0];

    for (int i =1; i< v_elem.size(); i++){
        if (i< n)sum+=v_elem[i];
        v_dists.push_back(v_elem[i]-v_elem[i-1]);
    }
    for (int j =0; j<v_dists.size(); j++)cout <<"dist "<< j<< " is " <<v_dists[j]<< endl;
    cout << "Sum of N first elems is : "<< sum << endl;
    return 0 ;
    }


    catch (runtime_error& e)
    {cerr << "range error my friend : "<< e.what()<< '\n';
        keep_window_open();
        return 1 ;
    }
 