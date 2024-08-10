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

int getLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
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

// first method

Node* MiddleNode(Node* head){
    int n = getLength(head);
    int position = n/2 + 1;

    Node* temp = head;
    while(position!=1){
        position--;
        temp = temp->next;
    }
    return temp;
}

// Second method slow and fast approach (tortise approach)

Node* MiddleNode2(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }
    return slow;
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
    InsertAtTail(head,tail,16);
    // InsertAtTail(head,tail,10);
    printLL(head);
    cout<<endl;

    Node* ans = MiddleNode2(head);
    cout<<ans->data;
}