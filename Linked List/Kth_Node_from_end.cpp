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

Node* reverse(Node* head){
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

Node* KthNode(Node* head,int pos){
    Node* startPoint = reverse(head);
    Node* temp = startPoint;
    for(int i=0;i<pos;i++){
        temp = temp->next;
    }
    return temp;
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
    InsertAtTail(head,tail,3);
    InsertAtTail(head,tail,2);
    InsertAtTail(head,tail,1);
    // InsertAtTail(head,tail,42);
    // InsertAtTail(head,tail,5);
    // InsertAtTail(head,tail,17);
    // InsertAtTail(head,tail,25);
    printLL(head);
    cout<<endl;
    Node* ans = KthNode(head,2);
    cout<<ans->data;
}
