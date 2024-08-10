#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string decodeMessage(string key,string message){
    char start = 'a';
    char mapping[300] = {0};

    // create mapping
    for(auto ch: key){
        if(ch !=' ' && mapping[ch]==0){
            mapping[ch] = start;
            start++;
        }
    }

    // use mapping to decode message
    string ans;
    for(auto ch: message){
        if(ch == ' '){
            ans.push_back(' ');
        }
        else{
            char decode = mapping[ch];
            ans.push_back(decode);
        }
    }
    return ans;
}

int main(){
    string key,message;
    getline(cin,key);
    getline(cin,message);
    string ans = decodeMessage(key,message);
    cout<<ans;
}