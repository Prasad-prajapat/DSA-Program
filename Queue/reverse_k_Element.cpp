#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void reversekElement(queue<int> &q,int k){
    stack<int> st;
    int n = q.size();

    if(k>n || k==0){
        return;
    }
    for(int i=0;i<k;i++){
        int element = q.front();
        q.pop();
        st.push(element);
    }

    while(!st.empty()){
        int temp = st.top();
        st.pop();
        q.push(temp);
    }

    for(int i=0;i<n-k;i++){
        int temp = q.front();
        q.pop();
        q.push(temp);
    }

}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    reversekElement(q,3);

    while(!q.empty()){
        int element = q.front();
        q.pop();
        cout<<element<<" ";
       
    }
}