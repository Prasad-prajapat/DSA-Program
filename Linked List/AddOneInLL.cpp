#include<bits/stdc++.h>
using namespace std;

class Node
{
    public:
        int data;
        Node* next;

        Node(){
            this->next = NULL;
        }

        Node(int data){
            this->data = data;
            this->next = NULL;
        }
};

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

Node* reverse(Node* &head){
    Node* prev = NULL;
    Node* curr = head;

    while(curr!=NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
    }
    return prev;
}

void addOne(Node* &head){
    // reverse
    head = reverse(head);
    // add one
    int carry = 1;
    Node* temp = head;
    while(temp->next!=NULL){
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum/10;
        temp->data = digit;
        temp = temp->next;
        if(carry==0){
            break;
        }
    }

    // process last node
    if(carry!=0){
        int totalSum = temp->data + carry;
        int digit = totalSum % 10;
        carry = totalSum/10;
        temp->data = digit;

        if(carry!=0){
            Node* newNode = new Node(carry);
            temp->next = newNode;
        }
    }
     // reverse
    head = reverse(head);
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
    InsertAtTail(head,tail,1);
    InsertAtTail(head,tail,9);
    // InsertAtTail(head,tail,9);
    // InsertAtTail(head,tail,40);
    // InsertAtTail(head,tail,50);
    // InsertAtTail(head,tail,60);
    printLL(head);
    cout<<endl;
    addOne(head);
    printLL(head);
}
