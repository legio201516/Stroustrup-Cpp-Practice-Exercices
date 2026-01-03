#include "std_lib_facilities.h"	

struct Point{

    int x;
    int y;
    Point(): x(0), y(0){}
};

istream& operator>> (istream& is, Point& p)
{
    char ch1,ch2,ch3;
    int a, b;
    is>>ch1>> a>>ch2>>b>>ch3;
    if (ch1!='('||ch2!=','||ch3!=')') {       
        is.clear(ios_base::failbit);
};
    p.x= a;
    p.y=b;
    cout <<"Lets check we get : "<< p.x<<p.y;
    return is;
}
ostream& operator<< (ostream& os, Point p)
{

    os<< '('<< p.x<<','<<p.y<<')'<< endl;
    return os;
}
bool operator!= (Point p1,Point p2 )
{
    return (!(p1.x==p2.x)&& (p1.y==p2.y));
}

constexpr int no_points= 7; 
int main()try {
    
    vector<Point> original_points;

    cout << "Write " << no_points << " points as pairs of coordinates with" 
         << " format (x,y):\n";

    while (original_points.size() < no_points) {
        Point p;
        if (cin >> p) {
            original_points.push_back(p);
        }
        else {
            cout << "That's not a point!\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
    }
    cout << "Now lets see what you've entered !";
    for (int i = 0; i <original_points.size(); i++){
        cout << original_points[i];
    }
    // drill 4
    cout << "Please now enter name of output file"<< endl;
    string name;
    cin >> name;
    ofstream ost(name.c_str());
    if (!ost) error("Can't open output file", name);
    cout << "Now lets output your points in the file !";
    for (int i = 0; i <original_points.size(); i++){
        ost << original_points[i];
    }
    // drill 5
    ost.close();
    ifstream ist(name.c_str());
    if (!ist) error("Can't open output file", name);
    vector<Point> processed_points;
    cout << "We get the points from your file"<< endl;
    for (int i = 0; i <original_points.size(); i++){
        Point current_point;
        ist >>current_point;
        processed_points.push_back(current_point);
    }
    // lets compare both vector s : 
    cout << "Now lets compare both vectors entered !";
    if (original_points.size()!=processed_points.size()) error (" Not same number of points !");
    for (int i = 0; i <original_points.size(); i++){
        cout << "original point "<<original_points[i]<< " processed point "
        <<processed_points[i]<< endl;
        if (processed_points[i]!=original_points[i])error ("not same points");
    }
} 
catch (exception& e ){
    cerr<< e.what()<< endl;
    return 1;
}
catch (...){
    cerr<< "Unknown exception !"<< endl;
    return 2;
} 
