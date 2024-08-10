#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<int> nextSmallerElement(vector<int>& arr){
    stack<int> st;
    vector<int> ans(arr.size());

    st.push(-1);
    for(int i=arr.size()-1;i>=0;i--){
        int curr = arr[i];
        while(st.top()!=-1 && arr[st.top()] >= curr){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

vector<int> prevSmallerElement(vector<int>& arr){
    stack<int> st;
    vector<int> ans(arr.size());

    st.push(-1);
    for(int i=0;i<arr.size();i++){
        int curr = arr[i];
        while(st.top()!=-1 && arr[st.top()] >= curr){
            st.pop();
        }
        ans[i] = st.top();
        st.push(i);
    }
    return ans;
}

int LargestRectangleArea(vector<int> &height){
    vector<int>next = nextSmallerElement(height);
    for(int i=0;i<next.size();i++){
        if(next[i] == -1){
            next[i] = next.size();
        }
    }

    vector<int>prev = prevSmallerElement(height);
    int maxArea = INT_MIN;
    for(int i=0;i<height.size();i++){
        int length = height[i];
        int width = next[i] - prev[i] - 1;
        int currArea = length * width;
        maxArea = max(maxArea,currArea);
    }
    return maxArea;
}

int main(){
    vector<int>arr{2,1,5,6,2,3};
    int ans = LargestRectangleArea(arr);

    cout<<"Largest area is : "<<ans<<endl;
    
    // print next small element index
    // vector<int>ans;
    // ans = prevSmallerElement(arr);
    // for(auto i: ans){
    //     cout<<i<<" ";
    // }
}