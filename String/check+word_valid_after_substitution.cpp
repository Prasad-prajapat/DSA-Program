#include<iostream>
#include<string>
using namespace std;


bool isValid(string s) {
        if(s.size()==0){
            return true;
        }
        int fnd = s.find("abc");
        if(fnd != string::npos){
            // found
            string left = s.substr(0,fnd);
            string right = s.substr(fnd+3,s.size());
            string ans = left+right;
            return isValid(ans);
        }
        return false;
}

int main(){
    string s = "abccba";
    bool ans = isValid(s);
    cout<<ans;
}