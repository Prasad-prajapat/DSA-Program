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

void Delete(Node* &head, Node* &tail,int position){
    int length = getLength(head);
    if(head == NULL){
        cout<<"Can't delete this position"<<endl;
        return;
    }

    if(head == tail){
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
    }

    if(position == 1){
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        head->prev = NULL;
        delete temp;
    }
    else if(position == length){
        Node* prevNode = tail->prev;
        prevNode->next = NULL;
        tail->prev = NULL;
        delete tail;
        tail = prevNode;
    }
    else{
        Node* prevNode = NULL;
        Node* currNode = head;
        while(position!=1){
            position--;
            prevNode = currNode;
            currNode = currNode->next;
        }
        Node* nextNode = currNode->next;

        prevNode->next = nextNode;
        currNode->prev = NULL;
        currNode->next = NULL;
        nextNode->prev = prevNode;
        delete currNode;
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
    InsertAtTail(head,tail,12);
    InsertAtTail(head,tail,14);
    InsertAtTail(head,tail,16);
    InsertAtTail(head,tail,15);
    InsertAtTail(head,tail,17);
    InsertAtTail(head,tail,18);
    printLL(head);
    cout<<endl;

    Delete(head,tail,4);
    printLL(head);
}