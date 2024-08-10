#include<iostream>
#include<stack>
using namespace std;

int longestValidParenthese(string s){
    stack<char>st;
    st.push(-1);
    int maxlen = 0;

    for(int i=0;i<s.length();i++){
        char ch = s[i];
        if(ch == '('){
            st.push(i);
        }
        else{
            st.pop();
            if(st.empty()){
                st.push(i);
            }
            else{
                int len = i - st.top();
                maxlen = max(len,maxlen);
            }
        }
    }
    return maxlen;
}

int main(){
    string s = ")()())()";
    int ans = longestValidParenthese(s);
    cout<<"Longest valid parentheses:"<<ans;
}