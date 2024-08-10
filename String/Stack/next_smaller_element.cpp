#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmallerElement(int *arr,int &size){
    stack<int> st;
    vector<int> ans(size);
    st.push(-1);
    for(int i=size-1;i>=0;i--){
        int temp = arr[i];
        while(st.top() >= temp){
            st.pop();
        }

        ans[i] = (st.top());
        st.push(temp);
    }
    return ans;
}

vector<int> prevSmallerElement(int *arr,int &size){
    stack<int> st;
    vector<int> ans(size);
    st.push(-1);
    for(int i=0;i<size;i++){
        int temp = arr[i];
        while(st.top() >= temp){
            st.pop();
        }

        ans[i] = (st.top());
        st.push(temp);
    }
    return ans;
}

int main(){
    int arr[] = {8,4,6,2,3};
    int size = 5;
    vector<int>ans;
    // ans = prevSmallerElement(arr,size);
    ans = nextSmallerElement(arr,size);
    
    for(auto i : ans){
        cout<<i<<" ";
    }

}