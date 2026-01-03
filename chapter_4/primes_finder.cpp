using namespace std;
#include "std_lib_facilities.h"
bool is_prime(int n, vector<int> primes){

    for (int i=0;i<primes.size(); i++){
        if (n%primes[i]==0){
            return false;
        
        }
    }
    return true;
}
int main () {
    cout << "enter a max int for our prime numbers research : "<< endl;
    int max;
    cin >> max;
    vector<int> v_primes(1);
    v_primes[0]=2;
    for (int i =2;i<=max;i++ ){
        if (is_prime(i,v_primes)==true){
            v_primes.push_back(i);
            cout << "Just added "<< i<< " to primes numbers ";
        }
    
    }
    return 0;  }