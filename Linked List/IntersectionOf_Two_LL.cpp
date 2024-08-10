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

Node* getIntersectionNode(Node* headA,Node* headB){
    Node* a = headA;
    Node* b = headB;

    while(a->next!=NULL && b->next!=NULL){
        if(a == b){
            return a;
        }
        a = a->next;
        b = b->next;
    }

    if(a->next == NULL){
        int blen = 0;
        while(b->next!=NULL){
            blen++;
            b = b->next;
        }

        while(blen--){
            headB = headB->next;
        }
    }
    else{
        int alen = 0;
        while(a->next!= NULL){
            alen++;
            a = a->next;
        }

        while(alen--){
            headA = headA->next;
        }
    }

    while(headA != headB){
        headA = headA->next;
        headB = headB->next;
    }

    return headA;
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

    Node* head1 = NULL;
    Node* tail1 = NULL;
    InsertAtTail(head1,tail1,3);
    InsertAtTail(head1,tail1,2);
    InsertAtTail(head1,tail1,1);
    InsertAtTail(head1,tail1,7);
    // InsertAtTail(head1,tail1,8);
     printLL(head1);
    cout<<endl;
    head1->next->next = head->next;

    Node* ans = getIntersectionNode(head,head1);
    cout<<"Intersection point is : "<<ans->data;
}