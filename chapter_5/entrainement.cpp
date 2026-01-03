using namespace std;
#include "std_lib_facilities.h"



int main(){
    try{
        // insèrer ici le code : 
        cin<< "sucess !";
        keep_window_open();
        return 0;
    }
    catch(exception& e){
        cerr<< "error : "<< e.what()<< '\n';
        keep_window_open();
        return 1;  
    }
    catch(...){
        cerr << "error oops, unknown exception ! \n";
        keep_window_open();
        return 2;
    }


return 0;}