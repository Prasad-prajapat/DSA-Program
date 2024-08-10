#include<iostream>
using namespace std;

class Queue{
    public:
        int* arr;
        int size;
        int front;
        int rear;

        Queue(int size){
            arr = new int[size];
            this->size =size;
            front = -1;
            rear = -1;
        }

        void push(int val){
            // Overflow
            if(rear == size-1){
                cout<<"Queue Overflow"<<endl;
            }
            // empty() ->first element
            else if(front == -1 && rear == -1){
                front++;
                rear++;
                arr[rear] = val;
            }
            // normal case
            else{
                rear++;
                arr[rear] = val;
            }
        }

        void pop(){
            // Underflow
            if(front == -1 && rear == -1){
                cout<<"Queue Underflow"<<endl;
            }
            // single element
            else if(front == rear){
                arr[front] = -1;
                front = -1;
                rear = -1;
            }
            // Normal case
            else{
                arr[front] = -1;
                front++;
            }
        }

        bool isEmpty(){
            if(front == -1 && rear == -1){
                return true;
            }
            else{
                return false;
            }
        }

        int getSize(){
            if(front == -1 && rear == -1){
                return 0;
            }
            else{
                return rear-front+1;
            }
        }

        int getFront(){
            if(front == -1){
                cout<<"No element in queue"<<endl;
                return -1;
            }
            else{
                return arr[front];
            }
        }

        int getback(){
            if(rear == -1){
                cout<<"No element in queue"<<endl;
                return -1;
            }
            else{
                return arr[rear];
            }
        }

        void print(){
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};

int main(){
    Queue q(5);
    q.print();

    q.push(10);
    q.print();

    // q.push(20);
    // q.print();

    // q.push(30);
    // q.print();

    // q.push(40);
    // q.print();

    // q.push(50);
    // q.print();

    // q.pop();
    // q.print();

    // q.pop();
    // q.print();


    cout<<q.getSize();
    cout<<endl;
    cout<<q.getFront();
      cout<<endl;
    cout<<q.getback();

}