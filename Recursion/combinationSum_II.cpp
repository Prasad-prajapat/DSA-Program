#include<bits/stdc++.h>
using namespace std;

void CombinationSum_Helper(vector<int>&candidate,int target,vector<vector<int>>&ans,vector<int>&v,int index){
    // base case
    if(target == 0){
        ans.push_back(v);
        return;
    }
    if(target < 0){
        return;
    }

    for(int i=index;i<candidate.size();i++){
        if(i>index && candidate[i] == candidate[i-1]){
            continue;
        }
        v.push_back(candidate[i]);
        CombinationSum_Helper(candidate,target-candidate[i],ans,v,i+1);
        v.pop_back();
    }
}

vector<vector<int>> CombinationSum(vector<int>&candidate,int target){
    sort(candidate.begin(),candidate.end());
    vector<vector<int>>ans;
    vector<int>v;
    CombinationSum_Helper(candidate,target,ans,v,0);
    // set<vector<int>>st;
    // for(auto e : ans){
    //     st.insert(e);
    // }
    // ans.clear();
    // for(auto e : st){
    //     ans.push_back(e);
    // }
    return ans;
}

int main(){
    vector<int>candidate{2,5,2,1,2};
    int target = 5;
    vector<vector<int>>ans;
    ans = CombinationSum(candidate,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}