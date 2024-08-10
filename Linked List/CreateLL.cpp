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

void printLL(Node *head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp = temp->next;
    }
}

int main(){
    Node *first = new Node(1);
    Node *second = new Node(2);
    Node *third = new Node(3);
    Node *four = new Node(4);

    Node* head = first;
    first->next = second;
    second->next = third;
    third->next = four;
    printLL(head);
}