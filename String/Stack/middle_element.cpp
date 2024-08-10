#include<iostream>
#include<stack>
using namespace std;

void solve(stack<int> &st,int &pos,int &ans){
    if(pos == 1){
        ans =  st.top();
        return;
    }
    pos--;
    int temp = st.top();
    st.pop();

    // recursion
    solve(st,pos,ans);

    // Backtracking
    st.push(temp);  
}

int getMiddleElement(stack<int> &st){
    int size = st.size();
    if(st.empty()){
        return -1;
    }
    else{
        int pos = 0;
        if(size & 1){
            pos = (size/2) + 1;
        }
        else{
            pos = size/2;
        }
        int ans = -1;
        solve(st,pos,ans);
        return ans;
    }
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(33);
    st.push(47);
    st.push(25);
    st.push(37);
    st.push(43);

    int mid = getMiddleElement(st);
    cout<<"Middle Element : "<<mid<<endl;
}