#include<iostream>
using namespace std;

class Node{
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

// Iteratively

void reverseLL(Node* &head){
    Node* prev = NULL;
    Node* curr = head;
    while(curr!=NULL){
        Node* nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode; 
    }
    head = prev;
}

//Recursivelly

Node* reverseRecursiveLL(Node* &head,Node* prev, Node* curr){
    // Base case
    if(curr == NULL){
        head = prev;
        return head;
    }
    Node* nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
    Node* aagekaAns = reverseRecursiveLL(head,prev,curr);
    return aagekaAns;
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
    InsertAtTail(head,tail,2);
    InsertAtTail(head,tail,4);
    InsertAtTail(head,tail,6);
    InsertAtTail(head,tail,8);
    InsertAtTail(head,tail,10);
    printLL(head);
    cout<<endl;
    // reverseLL(head);
    reverseRecursiveLL(head,NULL,head);
    printLL(head);

}