#include<iostream>
#include<stack>
using namespace std;

int countReversal(string s){
    if(s.size() & 1){
        return -1;
    }
    stack<char>st;
    int count = 0;
    for(auto ch : s){
        if(ch == '{'){
            st.push(ch);
        }
        else{
            if(!st.empty() && st.top() == '{'){
                st.pop();
            }
            else{
                st.push(ch);
            }
        }
    }

    while(!st.empty()){
        char ch1 = st.top();
        st.pop();
        char ch2 = st.top();
        st.pop();
        if(ch1 == ch2){
            count += 1;
        }
        else{
            count += 2;
        }
    }
    return count;
}

int main(){
    string s = "}{{}}{{}";
    int ans = countReversal(s);
    cout<<"Minimum count of reversal:"<<ans;
}