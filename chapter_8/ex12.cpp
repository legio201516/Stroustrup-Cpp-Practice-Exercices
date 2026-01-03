#include "std_lib_facilities.h"

struct Stats {
    double max{0};
    double min{0};
    double mean{0};
    double median{0};
};

void printstats( Stats stats)
// Only read arguments, so it safe to pass them by const-reference
{
    cout << "Here are the stats of your vector : ";
    cout << " Max :  " <<stats.max<< endl;
    cout << " Min :  "<<stats.min<< endl;
    cout << " Mean :  "<<stats.mean<< endl;
    cout << " Median :  "<<stats.median<< endl;

}
double mean(const vector<double>& data){
    double sum=0;
    for (int i= 0; i < data.size(); i++){
        sum+=data[i];
    }
    return sum/data.size();
}

double median(const vector<double>& data){
    // supposes to get a sorted vector !
    int n= data.size();
    switch (n%2){
        case 0 : 
        return (data[n/2]+data[(n-2)/2])/2;
        case 1: 
        return data[n-1/2];
    }
}
Stats getstats( const vector<double>& data){// function to get the stats from gthe vector
    vector<double> tmp = data;
    sort(tmp.begin(), tmp.end());
    Stats stats;
    stats.min= tmp[0];
    stats.max= tmp[tmp.size()-1];
    stats.mean=mean(tmp);
    stats.median=median(tmp);
    return stats;

}

int main(){
    printstats(getstats({1,4,3,2}));
    return 0;
}