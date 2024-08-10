#include<iostream>
#include<stack>
using namespace std;

void insertSorted(stack<int> &st,int element){
    // base case
    if(st.empty() || element > st.top()){
        st.push(element);
        return;
    }
    int temp = st.top();
    st.pop();
    insertSorted(st,element);
    st.push(temp);
}

int main(){
    stack<int>st;
    st.push(10);
    st.push(20);
    st.push(30);
    st.push(40);
    int element = 25;
    // insertSorted(st,element);
    print(st);  
}