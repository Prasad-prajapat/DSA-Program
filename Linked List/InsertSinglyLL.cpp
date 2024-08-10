#include<iostream>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(){
            this->data = 0;
            this->next = NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
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

void InsertAthead(Node* &head, Node* &tail,int data){
    if(head == NULL){
        // LL is empty
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        // LL is non empty
        Node* newNode = new Node(data);
        // Attached node to head
        newNode->next = head;
        // Update head
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
        tail = newNode;
    }
}

void InsertAtPosition(Node* &head, Node* &tail,int data,int position){
    int length = getLength(head);

    if(position == 1){
        InsertAthead(head,tail,data);
    }
    else if(position == length + 1){
        InsertAtTail(head,tail,data);
    }
    else{
        Node* newNode = new Node(data);
        Node* prev = NULL;
        Node * curr = head;
        while(position!=1){
            position--;
            prev = curr;
            curr = curr->next;
        }
        prev->next = newNode;
        newNode->next = curr;
    }
}


void printLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
}

int main(){
    Node* head = NULL;
    Node* tail = NULL;
    InsertAthead(head,tail,30);
    InsertAthead(head,tail,20);
    InsertAthead(head,tail,10);
    InsertAtTail(head,tail,50);
    InsertAtPosition(head,tail,100,5);
    printLL(head);

}