#include<bits/stdc++.h>
using namespace std;

int solve(vector<int>&coins,int amount){
    // Base case
    if(amount == 0){
        return 0;
    }
    if(amount < 0){
        return INT_MAX;
    }

    int mini = INT_MAX;

    for(int i=0;i<coins.size();i++){
        int coin = coins[i];
        if(coin <= amount){
            int recAns = solve(coins,amount-coin);
                if(recAns != INT_MAX){
                int ans = 1 + recAns;
                mini = min(mini,ans);
            }
        }
    }
    return mini;
}

int main(){
    vector<int>coins{1,2,5};
    int amount = 11;
    int ans = solve(coins,amount);
    cout<<ans;
}