#include<iostream>
#include<vector>
using namespace std;

void createMapping(string& s){
    char start = 'a';
    char hash[256] = {0};
    for(int i=0;i<s.length();i++){
        if(hash[s[i]] == 0){
            hash[s[i]] = start;
            start++;
        }   
    }
    // update string
    for(int i=0;i<s.length();i++){
        char ch = s[i];
        s[i] = hash[ch];
    }
}

vector<string> findAndReplacePattern(vector<string>& words, string pattern){
    vector<string> ans;

    createMapping(pattern);
    for(auto s: words){
        string tempString = s;
        createMapping(tempString);
        if(tempString == pattern){
            ans.push_back(s);
        }
    }
    return ans;
}

int main(){
    vector<string> v = {"abc","deq","mee","aqq","dkd","ccc"};
    string pattern = "abb";

    vector<string> ans;
    ans = findAndReplacePattern(v,pattern);
    for(auto s:ans){
        cout<<s<<endl;
    }
}