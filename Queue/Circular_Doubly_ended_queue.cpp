#include<iostream>
using namespace std;

class Cdequeue{
    public:
        int* arr;
        int size;
        int front;
        int rear;

        Cdequeue(int size){
            arr = new int[size];
            this->size =size;
            front = -1;
            rear = -1;
        }

        void pushFront(int val){
            // overflow
            if((front == 0 && rear == size-1) || rear == front -1){
                cout<<"Overflow"<<endl;
            }

            // empty()- -> first element
            else if(front == -1 && rear == -1){
                front++;
                rear++;
                arr[front] = val;
            }

            // Circular nature
            else if(front == 0 && rear != size-1){
                front = size-1;
                arr[front] = val;
            }
            else{
                front--;
                arr[front] = val;
            }
        }

        void pushBack(int val){
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

        void popFront(){
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

        void popBack(){
            // underflow
            if(front == -1 && rear == -1){
                cout<<"Circular queue underflow"<<endl;
            }

            // single element
            else if(front == rear){
                arr[rear] = -1;
                front = -1;
                rear = -1;
            }

            // circular nature
            else if(rear == 0){
                arr[rear] = -1;
                rear = size-1;
            }

            else{
                arr[rear] = -1;
                rear--;
            }
        }

        void print(){
            cout<<"Front "<<front<<" "<<"Rear "<<rear<<endl;
            for(int i=0;i<size;i++){
                cout<<arr[i]<<" ";
            }
            cout<<endl;
            cout<<endl;
        }
};

int main(){
    Cdequeue q(5);
    q.print();

    // q.pushBack(50);
    // q.print();

    // q.pushBack(60);
    // q.print();
    // q.pushBack(70);
    // q.print();
    // q.pushBack(80);
    // q.print();

    // q.popFront();
    // q.print();
    q.pushFront(90);
    q.print();
}