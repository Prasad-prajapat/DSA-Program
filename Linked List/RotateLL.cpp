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

void InsertAtTail(Node* &head,Node* &tail,int data){
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

    Node* rotateRight(Node* head, int k) {
        if(head == NULL){
            return 0;
        }
        int len = getLength(head);
        int actualRotateK = k % len;
        if(actualRotateK == 0){
            return head;
        }

        int newlastNodePos = len - actualRotateK -1;
        Node* newlastNode = head;
        for(int i=0;i<newlastNodePos;i++){
            newlastNode = newlastNode->next;
        }
        Node* newhead = nullptr;
        newhead = newlastNode->next;
        newlastNode->next = NULL;
        Node* it = newhead;
        while(it->next){
            it = it->next;
        }
        it->next = head;
        return newhead;
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
    InsertAtTail(head,tail,4);
    InsertAtTail(head,tail,12);
    InsertAtTail(head,tail,7);
    printLL(head);
    cout<<endl;

    int k = 2;
    Node* ans = rotateRight(head,k);
    printLL(ans);
}    