#include<iostream>
using namespace std;

string encrypt(string text,int x){
    string ans = "";
    for(int i=0;i<text.length();i++){
        char ch = text[i];
        if(ch >= 127 || ch <0){
            cout<<"character is invalid"<<endl;
        }
        if(ch >= 97 && ch <=122){
            ans += ch -32 + x;
        }
        else if(ch >= 65 && ch <=96){
            ans += ch + 32 + x;
        }
        else{
            ans += (ch + x);
        }
      
    }
    return ans;
 }

int main(){
    string text;
    cout<<"Enter the input String: ";
    cin>>text;
    cout<<"Enter the shift value: ";
    int x;
    cin>>x;
    
    string ans = encrypt(text,x);
    cout<<"encrypt string: "<<ans;
}