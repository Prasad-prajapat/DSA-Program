#include<iostream>
#include<queue>
using namespace std;

void printFirstNegative(int* arr,int size,int k){
    queue<int> q;

    // Process first k element - first window
    for(int i=0;i<k;i++){
        if(arr[i]<0){
            q.push(i);
        }
    }

    for(int index = k;index<size;index++){
        if(q.empty()){
            cout<<"0"<<endl;
        }
        else{
            cout<<arr[q.front()]<<" ";
        }

        // removeing
        if(index - q.front() >= k){
            q.pop();
        }

        // addition
        if(arr[index] < 0){
            q.push(index);
        }
    }

    // last window
    if(q.empty()){
        cout<<"0"<<endl;
    }
    else{
        cout<<arr[q.front()]<<" ";
    }

}

int main(){
    int arr[] = {2,-5,4,-1,-2,0,5};
    int size = 7;
    printFirstNegative(arr,size,3);

}