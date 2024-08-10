#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

void maxprofitfinder(vector<int>&prices,int i,int&minprice,int&maxprofit){
    // Base case
    if(i == prices.size()){
        return;
    }

    // one case solve
    if(prices[i] < minprice){
        minprice = prices[i];
    }
    int todayProfit = prices[i] - minprice;
    if(todayProfit > maxprofit){
        maxprofit = todayProfit;
    }

    maxprofitfinder(prices,i+1,minprice,maxprofit);
}

int maxprofit(vector<int>&prices){
    int minprice = INT_MAX;
    int maxprofit = INT_MIN;
    maxprofitfinder(prices,0,minprice,maxprofit);
    return maxprofit;
}

int main(){
    vector<int>prices{7,1,5,3,6,4};
    int ans = maxprofit(prices);
    cout<<ans;
}



// #include<bits/stdc++.h>
// using namespace std;

// int maxProfit(vector<int>&prices){
//     int min = INT_MAX;
//     int index = -1;
//     for(int i=0;i<prices.size();i++){
//         if(min > prices[i]){
//             min = prices[i];
//             index = i;
//         }
//     }

//     int max = INT_MIN;
//     for(int j = index; j < prices.size();j++){
//         if(max < prices[j]){
//             max = prices[j];
//         }
//     }
//     int profit = max - min;
//     return profit;
// }

// int main(){
//     vector<int>prices{7};
//     int ans = maxProfit(prices);
//     cout<<"Maximum profit: "<<ans;
// }