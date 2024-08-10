#include<iostream>
#include<bits/stdc++.h>
using namespace std;

string str;
bool comparator(char a , char b){
    return (str.find(a) < str.find(b));
}

string customSorting(string order, string s){
    str = order;
    sort(s.begin(),s.end(),comparator);
    return s;
}

int main(){
    string order,key;
    cin>>order>>key;
    string ans = customSorting(order,key);
    cout<<ans;
}