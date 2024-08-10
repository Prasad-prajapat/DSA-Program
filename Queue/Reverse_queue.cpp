#include<iostream>
#include<stack>
#include<queue>
using namespace std;

// Using stack

// void reverseQueue(queue<int> &q){
//     stack<int> st;

//     while(!q.empty()){
//         int frontElement = q.front();
//         q.pop();
//         st.push(frontElement);
//     }

//     while(!st.empty()){
//         int val = st.top();
//         st.pop();
//         q.push(val);
//     }
// }

// Using recursion

void reverse(queue<int> &q){
    // base case
    if(q.empty()){
        return ;
    }
    int temp = q.front();
    q.pop();
    reverse(q);
    q.push(temp);
}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);
    
    // reverseQueue(q);

    reverse(q);

    while(!q.empty()){
        int element = q.front();
        q.pop();
        cout<<element<<" ";
       
    }
}