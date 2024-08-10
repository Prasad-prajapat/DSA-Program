#include<iostream>
using namespace std;

class Cqueue{
    public:
        int* arr;
        int size;
        int front;
        int rear;

        Cqueue(int size){
            arr = new int[size];
            this->size =size;
            front = -1;
            rear = -1;
        }

        void push(int val){
            // overflow
            if((front == 0 && rear == size-1) || rear == front -1){
                cout<<"Circular queue overflow"<<endl;
            }

            // empty()- -> first element
            else if(front == -1 && rear == -1){
                front++;
                rear++;
                arr[rear] = val;
            }

            // Circular Nature
            else if(rear == size-1 && front!=0){
                rear = 0;
                arr[rear] = val;
            }

            // Normal case
            else{
                rear++;
                arr[rear] = val;
            }
        }

        void pop(){
            // underflow
            if(front == -1 && rear == -1){
                cout<<"Circular queue underflow"<<endl;
            }

            // single element
            else if(front == rear){
                arr[front] = -1;
                front = -1;
                rear = -1;
            }

            // Circular nature
            else if(front == size-1){
                arr[front] = -1;
                front = 0;
            }

            // Normal case
            else{
                arr[front] = -1;
                front++;
            }
        }

        void print(){
            cout<<"Front "<<front<<" "<<"Rear "<<rear<<endl;
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
        }
};



int main(){
    Cqueue q(4);
    q.print();

    q.push(15);
    q.print();

    q.push(18);
    q.print();

    q.push(17);
    q.print();

    q.push(25);
    q.print();

    q.pop();
    q.print();

    q.push(100);
    q.print();
    q.push(14);
}