#include<iostream>
#include<bits/stdc++.h>
using namespace std;

static bool mycomp(string a, string b){
    string t1 = a+b;
    string t2 = b+a;
    return t1>t2;
}

string largestNumber(vector<int>& nums){
    vector<string> snums;
    for(auto s: nums){
        snums.push_back(to_string(s));
    }
    sort(snums.begin(),snums.end(),mycomp);
    if(snums[0] == "0"){
        return "0";
    }

    string ans="";
    for(auto str: snums){
        ans = ans + str;
    }
    return ans;
}

int main(){
    vector<int> v = {3,30,34,5,9};
    
    string ans = largestNumber(v);
    cout<<"Largest number is : "<<ans;
}