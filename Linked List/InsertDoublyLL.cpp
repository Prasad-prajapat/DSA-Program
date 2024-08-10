#include<iostream>
using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;

        Node(){
            this->next = NULL;
            this->prev = NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
            this->prev = NULL;
        }
};

int getLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

void InsertAtHead(Node* &head, Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
    }
}

void InsertAtTail(Node* &head, Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void InsertAtPosition(Node* &head, Node* &tail,int data,int position){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        int len = getLength(head);
        if(position == 1){
            InsertAtHead(head,tail,data);
        }
        else if(position == len+1){
            InsertAtTail(head,tail,data);
        }
        else{
            Node* newNode = new Node(data);
            Node* prevNode = NULL;
            Node* currNode = head;
            while(position!=1){
                position--;
                prevNode = currNode;
                currNode = currNode->next;
            }
            prevNode->next = newNode;
            newNode->prev =  prevNode;
            newNode->next = currNode;
            currNode->prev = newNode;
        }
    }
}

void printLL(Node * head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    InsertAtHead(head,tail,2);
    InsertAtHead(head,tail,4);
    InsertAtHead(head,tail,6);
    InsertAtHead(head,tail,8);
    InsertAtTail(head,tail,1);
    printLL(head);
    cout<<endl;
    InsertAtPosition(head,tail,50,4);
    printLL(head);
}