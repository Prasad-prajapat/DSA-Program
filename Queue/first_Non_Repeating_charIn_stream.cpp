#include<iostream>
#include<queue>
using namespace std;

int main(){
    string s= "ababc";
    queue<char> q;
    int freq[26] = {0};

    for(int i=0;i<s.length();i++){
        char ch = s[i];
        // update the frequency
        freq[ch-'a']++;
        // push into the queue
        q.push(ch);

        // find ans 
        while(!q.empty()){
            char frontCharacter = q.front();
            if(freq[frontCharacter-'a'] > 1){
                q.pop();
            }
            else{
                cout<<frontCharacter<<"->";
                break;
            }
        }

        if(q.empty()){
            cout<<"#"<<"-->";
        }
    }
}