#include<bits/stdc++.h>
using namespace std;

int compress(vector<char>& char1){
    int index = 0, count = 1;
    char prev = char1[0];
    for(int i=1;i<char1.size();i++){
        if(prev == char1[i]){
            count++;
        }
        else{
            char1[index++] = prev;
            if(count>1){
                int start = index;
                while(count){
                    char1[index++] = (count % 10) + '0';
                    count = count/10;
                }
                reverse(char1.begin()+start , char1.begin()+index);
            }
            prev = char1[i];
            count = 1;
        }
    }

    char1[index++] = prev;
    if(count>1){
            int start = index;
            while(count){
                char1[index++] = (count % 10) + '0';
                count = count/10;
            }
            reverse(char1.begin()+start , char1.begin()+index);
        }
    return index;
}

int main(){
    vector<char> char1;
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
        char c;
        cin>>c;
        char1.push_back(c);
    }
    cout<<compress(char1);
}