using namespace std;
#include "std_lib_facilities.h"


int main () {
    cout << "Give the max int you want, we wil give you  : "
    int n ; 
    cin >> n ;
   
    vector<int> v_primes(101);
    int max = 100;
    for (int i =2;i<=max;i++ ){
        if (v_primes[i]==0){   
            // he is unmarked, so a prime number, so we check all his multiples and mark them.
            int counter =2;
            while (counter*i <=max){
                v_primes[counter*i]=1;
                counter++;
            }
        

        }}

    
    cout << "Primes between 1 and " << max << ":\n";
    for (int i=2; i <= max; ++i){
        if (v_primes[i] == 0) cout << i << '\n';
    
    }
    return 0;  }