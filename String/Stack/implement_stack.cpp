#include<iostream>
#include<stack>
using namespace std;

class Stack
{
    public:
        int* arr;
        int size;
        int top;

        Stack(int size){
            arr = new int[size];
            this->size = size;
            top = -1;
        }

        void push(int data){
            if(top == size-1){
                cout<<"OVERFLOW"<<endl;
            }
            else{
                top++;
                arr[top] = data;
            }
        }

        void pop(){
            if(top == -1){
                cout<<"UNDERFLOW"<<endl;
            }
            else{
                arr[top] = 0;
                top--;
            }
        }

        bool isEmpty(){
            if(top == -1){
                return true;
            }
            else{
                false;
            }
        }

        int getTop(){
            if(top == -1){
                cout<<"UNDERFLOW"<<endl;
                return -1;
            }
            else{
                return arr[top];
            }
        }

        int getSize(){
            return top+1;
        }

        // void print(){
        //     for(int i=0;i<size;i++){
        //         cout<<arr[i]<<" ";
        //     } 
        //     cout<<endl;
        // }
};

int main(){
    Stack st(6);
    st.push(10);
    st.push(20);
    st.push(15);
    st.pop();
    // st.print();

}