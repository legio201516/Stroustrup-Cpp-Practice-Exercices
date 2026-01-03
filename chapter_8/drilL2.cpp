#include "std_lib_facilities.h"



void swap_v(int a, int b){
int temp; temp = a; a =b; b=temp;
}
void swap_r(int& a, int& b){
int temp; temp = a; a =b; b=temp;

}/*void swap_cr(const int& a, const int& b){
const int temp; temp = a; a =b; b=temp;
}*/

int main(){

    int x = 7;
    int y =9;
    swap_r(x,y);
    cout << x<< "\t"<< y<< endl;

    double dx = 7.7;
    double dy= 9.9;
    swap_v(dx,dy);
    cout << dx<< "\t"<< dy<< endl;
    return 0;
}

