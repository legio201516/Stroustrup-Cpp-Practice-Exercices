using namespace std;
#include "std_lib_facilities.h"
class Name_value{
    public:
    string name;
    int value;
    Name_value(string nm, int val)    // make a Name_value from a nm and a val;
        :name(nm), value(val) { }
};





bool is_already_in(string s, vector<Name_value> v){
       for (int i =0;i<v.size(); i++){
           if (v[i].name==s) return true;
   }       return false;
}
int main () {

    cout << " Please enter pairs of names and score like Barabara 22 ; "<< endl;
    int score;
    string name="unrecognized name ?";
    //vector<string> names;
    //vector<int> scores;
    vector<Name_value> v;
    bool entry = true;

    while((cin >> name>> score) and entry){
        if (name == "Termine" and score == 0){
            entry=false;
            cout << "Endin ! "<<endl;
            break;
        }
        else if (is_already_in(name,v)){
            cout << " Error ! Name is already registered !"<< endl;
        }
        else {
            Name_value nv = Name_value(name,score);
            v.push_back(nv);
        }
    }


    int n=v.size();
    for (int i =0;i<n; i++){
        cout 
        
        <<  v[i].name<< " "<< v[i].value << endl;
    }


    return 0 ; }