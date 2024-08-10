#include<iostream>
using namespace std;

string removeDuplicate(string s){
    string ans = "";
    int index = 0;
    while(index < s.length()){
        if(ans[ans.length()-1] == s[index] && ans.length()>0){
            ans.pop_back();
        }
        else{
            ans.push_back(s[index]);
        }
        index++;
    }
    return ans;
}

int main(){
    string str;
    cin>>str;
    cout<<"remove duplicate element string is : "<<removeDuplicate(str);
}