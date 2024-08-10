#include<iostream>
#include<stack>
#include<vector>
using namespace std;

int celebrity(vector<vector<int>>&M,int n)
{
    stack<int>st;

    // step 1 : push all person into stack
    for(int i=0;i<n;i++){
        st.push(i);
    }

    // step 2 : run discard method to get mightbecelebrity
    while(st.size()!=1){
        int a = st.top(); st.pop();
        int b = st.top(); st.pop();

        //  A knows B then A is not celebrity
        if(M[a][b] == 1){
            st.push(b);
        }
        else{
            // B knows A then B is not celebrity
            st.push(a);
        }
    }

    // step 3 : last person in stack might be celebrity
    int mightbeCelebrity = st.top();
    st.pop();
    for(int i=0;i<n;i++){
        if(M[mightbeCelebrity][i] != 0){
            return -1;
        }
    }

    for(int i=0;i<n;i++){
        if(M[i][mightbeCelebrity] != 1 && i != mightbeCelebrity){
            return -1;
        }
    }
    return mightbeCelebrity;

}

int main(){
    vector<vector<int>>v = {{0,0,1},{0,1,1},{0,0,0}};
    int n = 3;
    int ans = celebrity(v,n);
    cout<<ans;
}