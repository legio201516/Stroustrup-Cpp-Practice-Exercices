#include "std_lib_facilities.h"
namespace X {
    int var;
    void print(){
        cout << "hello from X"<<var;

    }
}
namespace Y {
    int var;
    void print(){
        cout << "hello from Y"<< var;

    }
}
namespace Z {
    int var;
    void print(){
        cout << "hello from Z"<< var;
    }
}

int main(){
    X::var=7;
    X::print();
    using namespace Y;
    var=9;
    print();
    {
        using Z::var;
        using Z::print ;

        var =11;
        print();
    }
    print();
    X::print();
    return 0;
}