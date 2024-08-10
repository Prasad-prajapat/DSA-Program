#include<bits/stdc++.h>
using namespace std;

int convertToMin(string &time){
    int hr = stoi(time.substr(0,2));
    int min = stoi(time.substr(3,2));
    return 60*hr + min;
}

int findMinDifference(vector<string> &timepoints){
    vector<int>mins;
    for(auto time: timepoints){
        mins.push_back(convertToMin(time));
    }
    sort(mins.begin(),mins.end());
    int ans = INT_MAX;
    for(int i=0;i<mins.size();i++){
        ans = min(ans,mins[i+1]-mins[1]);
    }

    int lastdiff = mins[0]+1440-mins[mins.size()-1];
    ans = min(ans,lastdiff);
    return ans;
}

int main(){
    vector<string> v{"00:00","23:59","00:00"};
    int ans = findMinDifference(v);
    cout<<ans;
}