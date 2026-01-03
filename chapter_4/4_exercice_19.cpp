using namespace std;
#include "std_lib_facilities.h"

bool is_already_in(string s, vector<string> v){
       for (int i =0;i<v.size(); i++){
           if (v[i]==s) return true;
   }       return false;
}
int main () {

    cout << " Please enter pairs of names and score like Barabara 22 ; "<< endl;
    int score;
    string name="unrecognized name ?";
    vector<string> names;
    vector<int> scores;
    bool entry = true;

    while((cin >> name>> score) and (name != "Termine" and score != 0)){
        if (name == "Termine" and score == 0){
            entry=false;
            cout << "Endin ! ";
        }
        else if (is_already_in(name,names)){
            cout << " Error ! Name is already registered !"<< endl;
        }
        else {
        names.push_back(name);
        scores.push_back(score);
        }
    }
    int n=scores.size();
    for (int i =0;i<n; i++){
        cout << names[i]<< " "<< scores[i]<< endl;
    }

    cout << " Ask for a name to get its score : ";
    string s;
    cin>> s;
    bool name_found=false;
    for (int i =0; i<n;i++){
        if (names[i]==s) {cout << scores[i]<< endl;
        name_found=true;}
        }

        if (!name_found){
            cout << " Name not found "<< endl;
        }


    cout << " Ask for a score to get its correspondind name(s) : ";
    int i =0;
    cin >> i;
    bool score_found=false;
    for (int j =0;j<n; j++){
        if (scores[j]==i){
            cout << names[j] << "\t";
            score_found=true;
        } 
    }
    if (!score_found){
        cout << " score not found "<< endl;
        }
    return 0 ; }