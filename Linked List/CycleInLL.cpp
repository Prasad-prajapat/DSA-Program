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

// check loop is present or not

// method 1 using map
// bool checkLoop(Node* head){
//     Node* temp = head;
//     map<Node*,bool>table;

//     while(temp!=NULL){
//         if(table[temp] == false){
//             table[temp] = true;
//         }
//         else{
//             return true;
//         }
//         temp = temp->next;
//     }
//     return false;
// }

// method 2 --> tortoise algorithm
bool detectCycle(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow){
            return true;
        }
    }
    return false;
}

// Starting point of loop

Node* StartingPointLoop(Node* head){
    Node* slow = head;
    Node* fast = head;

    while(fast!=NULL){
        fast = fast->next;
        if(fast!=NULL){
            fast = fast->next;
            slow = slow->next;
        }
        if(fast == slow){
            break;
        }
    }

    slow = head;
    while(fast != slow){
        slow = slow->next;
        fast = fast->next;
    }
    return fast;
}

void removeLoop(Node* &head){
    Node* startPoint = StartingPointLoop(head);
    Node* temp = startPoint;
    while(temp->next!=startPoint){
        temp = temp->next;
    }
    temp->next = NULL;
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
    InsertAtTail(head,tail,60);
    InsertAtTail(head,tail,70);
    InsertAtTail(head,tail,80);
    InsertAtTail(head,tail,90);

    
    tail->next = head->next->next->next;
    removeLoop(head);
    printLL(head);
    // bool ans = detectCycle(head);
    // cout<<ans;

    // Node* ans = StartingPointLoop(head);
    // cout<<ans->data;

}