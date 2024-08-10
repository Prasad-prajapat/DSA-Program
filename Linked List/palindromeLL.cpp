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

Node* reverseLL(Node* prev, Node* curr){
    if(curr == NULL){
        return prev;
    }
    Node* nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
    return reverseLL(prev,curr);
}

bool compare(Node* head, Node* head2){
    // compare both linked list
    while(head!=NULL && head2!=NULL){
        if(head->data != head2->data){
            return false;
        }
        else{
            head = head->next;
            head2 = head2->next;
        }
    }
    return true;
}

bool isPalindrome(Node* head){
    // break into two halves
    Node* slow = head;
    Node* fast = head;

    while(fast->next!=NULL){
        fast = fast->next;
        if(fast->next!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
    }

    Node* head2 = slow->next;
    slow->next =NULL;

    // Reverse second halves
    Node* prev = NULL;
    Node* curr = head2;
    head2 = reverseLL(prev,curr);

    bool ans = compare(head,head2);
    return ans;

    
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
    InsertAtTail(head,tail,2);
    InsertAtTail(head,tail,3);
    InsertAtTail(head,tail,2);
    InsertAtTail(head,tail,1);
    InsertAtTail(head,tail,1);
    printLL(head);
    bool ans = isPalindrome(head);
    cout<<endl;
    cout<<ans;
}