#include<iostream>
#include<vector>
#include<deque>
using namespace std;

int main(){
    vector<int> v(3);
    deque<int> q1,q2;

    for(int i=0;i<v.size();i++){
        cin>>v[i];
    }
    
    for(int i=0;i<v.size();i++){
        int curr = v[i];
        while(curr>0){

            if((curr & 1 )&& q1.size() < 6){
                q1.push_front(v.size() - i);
           
            }
            else if( q2.size() < 6){
                q2.push_front(v.size() - i);
                
            } 
            else{
                break;
            }
            curr--;
        }
    }

    cout<<"helicopter 1 : ";
    while(!q1.empty()){
        cout << q1.front() <<" ";
        q1.pop_front();
    }

    cout<<endl;
    cout<<"helicopter 2 : ";
    while(!q2.empty()){
        cout << q2.front() <<" ";
        q2.pop_front();
    }

    
}