#include<iostream>
#include<bits/stdc++.h>
using namespace std;

// brute force  --> o(nlogn)
bool validAnagram(string s , string t){
    sort(s.begin(),s.end());
    sort(t.begin(),t.end());

    return (s==t)?true:false;
}

// hashing method /counting method
bool isAnagram(string s, string t){
    int hash[256] = {0};
    for(int i=0;i<s.length();i++){
        hash[s[i]]++;
    }

    for(int i=0;i<t.length();i++){
        hash[t[i]]--;
    }

    for(int i=0;i<hash.size();i++){
        if(hash[i]!=0){
            return false;
        }
    }
    return true;
}

int main(){
    string s,t;
    cin>>s>>t;
    cout<<validAnagram(s,t);
}