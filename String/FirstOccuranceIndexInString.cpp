#include<iostream>
using namespace std;

// int strStr(string haystack, string needle){
//     int n = haystack.size();
//     int m = needle.size();

//     for(int i=0;i<=n-m;i++){
//         for(int j=0;j<m;j++){
//             if(needle[j]!=haystack[i+j]){
//                 break;
//             }
//             if(j == m-1){
//                 return i;
//             }
//         }
//     }
//     return -1;
// }

// using stl function
int strStr(string haystack, string needle){
    size_t found = haystack.find(needle);
    if(found != string :: npos){
        return found;
    }
    return -1;
}


int main(){
    string haystack,needle;
    cin>>haystack>>needle;
    int ans = strStr(haystack,needle);
    cout<<"First Occurance of string in index : "<<ans;
}