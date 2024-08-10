#include<bits/stdc++.h>
using namespace std;

// int main(){
//     vector<string>s = {"d","b","c","b","c","a"};
//     map<string,int>mp;
//     for(int i=0;i<s.size();i++){
//         mp[s[i]]++;
//     }

    // for(auto i : mp){
    //     cout<<i.first<<" "<<i.second<<endl;
    // }
// }

bool sortbysecdesc(const pair<int,int> &a,const pair<int,int> &b)
{
       return a.second>b.second;
}

int minimumPushes(string word) {
        vector<pair<char,int>>v;
        map<char,int>mp;
        for(int i=0;i<word.length();i++){
            char ch = word[i];
            mp[ch]++;
        }

        
        cout<<endl;
        for(auto i : mp){
            v.push_back(make_pair(i.first,i.second));
        }

        sort(v.begin(), v.end(), sortbysecdesc);

        for(auto i : v){
            cout<<i.first<<" "<<i.second<<endl;
        }
        // int count = 1;
        int ans = 0;
        for(auto i=0;i<v.size();i++){
            if(i <= 7){
                ans += v[i].second * 1;
            }
            else if(8 <= i <= 15){
                ans += v[i].second * 2;
            }
            else if(16 <= i <=23){
                ans += v[i].second*3;
            }
            else{
                ans += v[i].second * 4;
            }
            cout<<"i"<<i<<" "<<ans<<endl;
            // count++;
        }
        return ans;
    }

int main(){
    string s = "alporfmdqsbhncwyu";
    int ans =minimumPushes(s);
    cout<<ans;
}    