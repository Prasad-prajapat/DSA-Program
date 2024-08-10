#include<iostream>
using namespace std;

int expand(string s,int i,int j){
    int count=0;
    while(s[i] == s[j] && i>=0 && j<s.length()){
        count++;
        i--;
        j++;
    }
    return count;
}

int countSubstring(string s){
    int totalCount = 0;
    for(int center=0; center<s.length(); center++){
        // Odd Substring
        int countOdd = expand(s,center,center);
        // Even Substring
        int countEven = expand(s,center,center+1);
        totalCount = totalCount + countEven + countOdd;
    }
    return totalCount;
}

int main(){
    string str;
    cin>>str;
    int ans = countSubstring(str);
    cout<<ans;
}

