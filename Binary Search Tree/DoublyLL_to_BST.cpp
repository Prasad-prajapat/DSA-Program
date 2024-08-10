#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data = data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* insertToBST(Node* root,int data){
    if(root == NULL){
        root = new Node(data);
        return root;
    }
    if(root->data < data){
        root->right = insertToBST(root->right,data);
    }
    else{
        root->left = insertToBST(root->left,data);
    }
    return root;
}

void createBST(Node* &root){
    cout<<"Enter the data";
    int data;
    cin>>data;

    while(data!=-1){
        root = insertToBST(root,data);
        cin>>data;
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        if(front == NULL){
            cout<<endl;
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            cout<<front->data<<" ";
            if(front->left!=NULL){
                q.push(front->left);
            }
            if(front->right!=NULL){
                q.push(front->right);
            }
        }
    }
}

Node* DLLtoBST(Node* &head, int n){
    // Base case
    if(head == NULL || n < 0){
        return NULL;
    }
    // LNR
    // L
    Node* leftAns = DLLtoBST(head, n/2);

    // N
    Node* root = head;
    root->left = leftAns;
    head = head->right;

    //  R
    Node* rightAns = DLLtoBST(head,n-n/2-1);
    root->right = rightAns;
 
    return root;
}

void print(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp = temp->right;
    }
}

int main(){
    Node* head = NULL;

    Node* first = new Node(10);
    Node* second = new Node(20);
    Node* third = new Node(30);
     
    head = first;
    first->right = second;
    second->left = first;

    second->right = third;
    third->left = second;

    int n=3;
    Node* root = DLLtoBST(head,n);
    
    levelOrderTraversal(root);
}