#include<iostream>
#include<queue>
using namespace std;


void interLeaveQueue(queue<int> &first){
    queue<int> second;
    int size = first.size();

    // push first half of first queue in second queue
    for(int i=0;i<(size/2);i++){
        int temp = first.front();
        first.pop();
        second.push(temp);
    }

    // merge both the halves
    for(int i=0;i<(size/2);i++){
        int temp = second.front();
        second.pop();
        first.push(temp);

        temp = first.front();
        first.pop();
        first.push(temp);
    }

}

int main(){
    queue<int> q;
    q.push(10);
    q.push(20);
    q.push(30);
    q.push(40);
    q.push(50);
    q.push(60);

    interLeaveQueue(q);

    while(!q.empty()){
        int element = q.front();
        q.pop();
        cout<<element<<" ";
       
    }
}