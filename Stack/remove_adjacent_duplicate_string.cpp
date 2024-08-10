#include<bits/stdc++.h>
#include<stack>
using namespace std;

string removeDuplicate(string s){
    stack<char>st;
    for(auto ch : s){
        if(!st.empty() && st.top() == ch){
            st.pop();
        }
        else{
            st.push(ch);
        }
    }

    string ans;
    while(!st.empty()){
        ans += st.top();
        st.pop();
    }
    // cout<<ans<<endl;
    reverse(ans.begin(),ans.end());
    return ans;
}

int main(){
    string s = "abbaca";
    string ans = removeDuplicate(s);
    cout<<ans;
}


