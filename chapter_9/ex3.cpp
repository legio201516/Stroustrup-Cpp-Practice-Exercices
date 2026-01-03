#include "std_lib_facilities.h"

class Name_pairs{
    public: 
    void read_names();
    void read_ages();
    void print();
    void sort();
    vector<string> getNames();
    vector<double> getAges();

    private:
    vector<string> name;
    vector<double> age;
    
};
vector<string> Name_pairs::getNames(){
    cout << " get names :   "<< endl;
    return name;
}
vector<double> Name_pairs::getAges(){
        cout << " get ages :   "<< endl;

    return age;
}
void Name_pairs::read_names(){
    string quit = "quit";
    cout << " Please enter names, followed by 'quit' when you want to stop : ";
    string s;
    while (cin>>s) {
        if (s==quit) return;
        name.push_back(s);};
}
void Name_pairs::read_ages(){
    cout << " Please enter ages for those names, followed by '|' when you did them all : ";
    double a;
    while (cin>>a) age.push_back(a);
    if (age.size()!=name.size()) error(" Different name and age vector-size ! ");
}

ostream& operator<<(ostream& os, Name_pairs& np){
    Name_pairs pairs{np};
    const vector<string>& name{pairs.getNames()};
    const vector<double>& age{pairs.getAges()};
   
    if (name.size()==0) error("Can not print, no names entered ! ");
    for (int i=0; i<name.size(); i++){
        os << name[i]<<" , " <<age[i]  << endl;
    }
    return os;
}

void Name_pairs::sort(){
    int n = name.size();
    vector<string> copy_names = name;//old names order
    using std::sort;      // Compiler only saw a candidate; Name_pairs::sort()

    sort(name.begin(), name.end());// we sort the names.
    vector<double> copy_ages=age;// let's a compy of old age order vector

    for (int i = 0;i<n; i++){// we go through old order of vectors
        string current_name = copy_names[i];
        double current_age = copy_ages[i];

        for (int j = 0;j<n; j++){
            if (name[j]==current_name) { // we look for the name's new index j in the sorted name list
                int new_index = j;
                age[new_index]=current_age;}
        }
    }
    
}

int main()try {
    Name_pairs np = Name_pairs();
    np.read_names();
    np.read_ages();
    cout << " UNsorted "<< np<< endl;
    np.sort();
    cout << " sorted "<<np<< endl;
    return 0;
}
catch (exception& e ){
    cerr<< e.what()<< endl;
    return 1;
}
catch (...){
    cerr<< "Unknown exception !"<< endl;
    return 2;
} 