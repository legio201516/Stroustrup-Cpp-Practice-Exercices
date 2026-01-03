struct X{
// defines f 
    void f(int x){
        struct Y{

            int f(){
                return 1;}
            int m;
        };

        int m;
        m=x;//doens't use the int x passed to the m;
        Y m2;// Creates a Y object, 
        return f(m2.f());// and makes recurrent call to itself with arg x being 1
    }

    int m;
    // defines g 
    void g(int m){
        if(m) f(m+2);// if m is not 0 do f(2)
        else 
            g(m+2);
        // If m is 0 do g(2) ie f(4) and stop there
    }
    // function x in struct x
    X(){}//not-used
    void m3(){}// same
    void main(){
        X a;// X struct in X struct ??
        a.f(2);// does f(2) to the new X type object
    }

};