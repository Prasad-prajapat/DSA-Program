#include<iostream>
#include<string.h>
using namespace std;

string removeOccurance(string s,string part){
    while(s.find(part) != string::npos){
        s.erase(s.find(part), part.length());
    }
    return s;
}

int main(){
    string str,part;
    cin>>str>>part;

    cout<<"string is:"<<removeOccurance(str, part);
}