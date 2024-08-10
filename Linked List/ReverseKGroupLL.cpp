#include<iostream>
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

int getLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp!=NULL){
        len++;
        temp = temp->next;
    }
    return len;
}

Node* reverseKGroup(Node* head,int k){
    if(head == NULL){
        return head;
    }
    if(head->next == NULL){
        return head;
    }

    Node* prev = NULL;
    Node* curr = head;
    Node* nextNode = curr->next;
    int pos = 0;

    int len = getLength(head);
    if(len < k){
        return head;
    }

    // ek case hamne solve kiya

    while(pos < k){
        nextNode = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextNode;
        pos++;
    }
    
    // Recursion sambhal lega
    Node* RecursionKaAns = NULL;
    if(nextNode != NULL){
        RecursionKaAns = reverseKGroup(nextNode,k);
        head->next = RecursionKaAns;
    }

    return prev;

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
    int k = 2;
    InsertAtTail(head,tail,1);
    InsertAtTail(head,tail,9);
    InsertAtTail(head,tail,5);
    InsertAtTail(head,tail,40);
    // InsertAtTail(head,tail,50);
    printLL(head);
    cout<<endl;
    Node* ans = reverseKGroup(head,k);
    printLL(ans);
}