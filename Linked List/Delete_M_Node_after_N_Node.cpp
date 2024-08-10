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

void linkDelete(Node* head,int m,int n){
    if(head == NULL){
        return;
    }
    Node* temp = head;
    int pos = 0;
    while(pos < m-1){
        if(temp==NULL){
            return;
        }
        temp = temp->next;
        pos++;
    }
    if(temp == NULL){
        return;
    }
    Node* MthNode = temp;
    temp = MthNode->next;

    pos = 0;
    while(pos < n){
        if(temp == NULL){
            return;
        }
        Node* temp1 = temp->next;
        delete temp;
        temp = temp1;
        pos++;
    }
    MthNode->next = temp;
    linkDelete(temp,m,n);
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
    InsertAtTail(head,tail,15);
    InsertAtTail(head,tail,42);
    InsertAtTail(head,tail,5);
    InsertAtTail(head,tail,17);
    InsertAtTail(head,tail,25);
    printLL(head);
    cout<<endl;
    linkDelete(head,2,1);
    printLL(head);

}
