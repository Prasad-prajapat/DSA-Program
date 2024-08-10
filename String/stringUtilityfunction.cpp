#include<iostream>
#include<string.h>
using namespace std;

int main(){
    string name = "prasadprajapat";
    // cin>>name;
    // getline(cin , name);
    // cout<<name;

    // Length of string

    // cout<<"Length of string : "<<name.length()<<endl;
    // cout<<"Length of string : "<<name.size()<<endl;

    // string is empty or not   Empty-->true 

    // string temp = "";
    // cout<<"String is empty or not: "<<temp.empty()<<endl;

    // at(index) --> access the element
    // cout<<"Character at position 0 is: "<<name.at(0)<<endl;

    // cout<<"Front character of string is: "<<name.front()<<endl;
    // cout<<"Back character of string is: "<<name.back()<<endl;


    // string str1 = "Love";
    // string str2 = "Babbar";

    // cout<<"before appending "<<endl;
    // cout<<str1<<endl;
    // cout<<str2<<endl;

    // str1.append(str2);

    // cout<<"after appending "<<endl;
    // cout<<str1<<endl;
    // cout<<str2<<endl;

    // string desc = "This is a car";
    // desc.erase(4,3);
    // cout<<desc<<endl;

    // string str1 = "Love Babbar";
    // string str2 = "kumar";

    // str1.insert(5,str2);
    // cout<<"printing name: "<<str1<<endl;

    // str1.push_back('P');
    // cout<<str1<<endl;

    // str1.pop_back();
    // cout<<str1<<endl;

    //  Important find()
    // string str1 = "yaar tera super star desi kalakar";
    // string str2 = "staryy";

    // if(str1.find(str2) == string::npos){
    //     cout<<"Not Found"<<endl;
    // }
    // else{
    //     cout<<"Found"<<endl;
    // }

    // string str1 = "babbar";
    // string str2 = "Love";

    // if(str1.compare(str2) == 0){
    //     cout<<"Matching"<<endl;
    // }
    // else{
    //     cout<<"Not Matching"<<endl;
    // }


    string desc = "this is a car, big daddy of all suvs";
    cout<<desc.substr(19,5)<<endl;
}