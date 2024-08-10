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

        // ~Node(){
        //     cout<<"Destructor is called"<<endl;
        // }
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

void deleteNode(Node* &head, Node* &tail, int position){
    int length = getLength(head);
    if(head == NULL){
        cout<<"Can't delete this position"<<endl;
        return;
    }
    if(head == tail){
        // single element
        Node* temp = head;
        delete temp;
        head = NULL;
        tail = NULL;
        return;
    }
    
    if(position == 1){
        // First node ko delete karo
        Node* temp = head;
        head = head->next;
        temp->next = NULL;
        delete temp;
    }

    else if(position == length){
        // last node ko delete karo
        Node* prev = head;
        while(prev->next!=tail){
            prev = prev->next;
        }
        prev->next = NULL;
        delete tail;
        tail = prev;
    }

    else{
        Node* prev = NULL;
        Node* curr = head;
        while(position!=1){
            position--;
            prev = curr;
            curr = curr->next;
        }
        prev->next = curr->next;
        curr->next =NULL;
        delete curr;
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
    InsertAtTail(head,tail,10);
    InsertAtTail(head,tail,20);
    InsertAtTail(head,tail,30);
    InsertAtTail(head,tail,40);
    InsertAtTail(head,tail,50);
    printLL(head);
    cout<<endl;
    
    deleteNode(head,tail,2);
    printLL(head);
    deleteNode(head,tail,3);
    printLL(head);
    

}