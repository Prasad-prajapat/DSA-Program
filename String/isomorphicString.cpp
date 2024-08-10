#include<iostream>
#include<vector>
using namespace std;

bool isIsomorphic(string s, string t){

    int hash[256] = {0};
    bool istcharMapped[256] = {0};

    for(int i=0;i<s.size();i++){
        if(hash[s[i]]==0 && istcharMapped[t[i]]==0){
            hash[s[i]] = t[i];
            istcharMapped[t[i]] = true;
        }
    }

    for(int i=0;i<s.size();i++){
        if(char(hash[s[i]]) != t[i]){
            return false;
        }
    }
    return true;
}

int main(){
    string s,t;
    cin>>s>>t;
    if(isIsomorphic(s,t)){
        cout<<"given strings are isomorphic ";
    }
    else{
        cout<<"given strings are not isomorphic ";
    }
}