#include<iostream>
#include<vector>
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
        v.push_back(candidate[i]);
        CombinationSum_Helper(candidate,target-candidate[i],ans,v,i);
        v.pop_back();
    }
}

vector<vector<int>> CombinationSum(vector<int>&candidate,int target){
    vector<vector<int>>ans;
    vector<int>v;
    CombinationSum_Helper(candidate,target,ans,v,0);
    return ans;
}

int main(){
    vector<int>candidate{2,3,6,7};
    int target = 7;
    vector<vector<int>>ans;
    ans = CombinationSum(candidate,target);
    for(int i=0;i<ans.size();i++){
        for(int j=0;j<ans[i].size();j++){
            cout<<ans[i][j]<<" ";
        }
        cout<<endl;
    }
}