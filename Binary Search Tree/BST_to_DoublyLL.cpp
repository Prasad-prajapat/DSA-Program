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

// method 1
// void convertBSTtoDLL(Node* root, Node* &head){
//     if(root == NULL){
//         return ;
//     }
//     // RNL
//     convertBSTtoDLL(root->right,head);

//     // N
//     root->right = head;
//     if(head!=NULL){
//         head->left = root;
//     }
//     head = root;

//     // L
//     convertBSTtoDLL(root->left,head);
// }

// method 2
void convertBSTtoDLL(Node* root, Node* &head,Node* &temp){
    if(root == NULL){
        return;
    }
    // LNR
    convertBSTtoDLL(root->left,head,temp);
    if(head == NULL){
        head = temp = root;
        head->left = NULL;
        temp->right = NULL;
    }
    else{
        temp->right = root;
        root->left = temp;
        temp = root;
    }

    convertBSTtoDLL(root->right,head,temp);
}

void printDLL(Node* head){
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp = temp->right;
    }
}

int main(){
    Node* root = NULL;
    createBST(root);
    levelOrderTraversal(root);
    cout<<endl;
    // method 1
    // Node* head = NULL;
    // convertBSTtoDLL(root,head);
    // printDLL(head);

    // method 2
    Node* head = NULL;
    Node* temp = NULL;
    convertBSTtoDLL(root,head,temp);
    printDLL(head);
}