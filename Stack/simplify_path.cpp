#include<iostream>
#include<stack>
using namespace std;

void buildAns(stack<string>&st,string &ans){
    if(st.empty()){
        return;
    }
    string s = st.top();
    st.pop();
    buildAns(st,ans);
    ans = ans+s;
}

string simplifyPath(string path){
    stack<string> st;
    int i=0;
    while(i < path.size()){
        int start = i;
        int end = i+1;
        while(end < path.size() && path[end] != '/'){
            ++end;
        }
        string subPath = path.substr(start,end-start);
        i = end;

        if(subPath == "/" || subPath == "/."){
            continue;
        }
        if(subPath != "/.."){
            st.push(subPath);
        }
        else if(!st.empty()){
            st.pop();
        }
    }
    string ans = st.empty() ? "/":"";
    buildAns(st,ans);
    return ans;
}

int main(){
    string s = "/a//b////c/d//././/..";
    string ans = simplifyPath(s);
    cout<<ans;
}