#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string reverseOnlyLetter(string s){
    int i=0;
    int j=s.length()-1;
    while(i<j){
        if(isalpha(s[i]) && isalpha(s[j])){
            swap(s[i],s[j]);
            i++,j--;
        }
        else if(!isalpha(s[i])){
            i++;
        }
        else{
            j--;
        }
    }
    return s;
}

int main(){
    string s;
    cin>>s;
    cout<<reverseOnlyLetter(s);
}