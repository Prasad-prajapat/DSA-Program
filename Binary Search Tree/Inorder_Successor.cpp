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

Node* inOrderSuccessor(Node* root, int x){
    Node* curr = root;
    Node* succ = 0;

    while(curr){
        if(curr->data > x){
            succ = curr;
            curr = curr->left;
        }
        else{
            curr = curr->right;
        }
    }
    return succ;
}

Node* inOrderPredecessor(Node* root,int x){
    Node* curr = root;
    Node* pred = 0;

    while(curr){
        if(curr->data < x){
            pred = curr;
            curr = curr->right;
        }
        else{
            curr = curr->left;
        }
    }
    return pred;
}

int main(){
    Node* root = NULL;
    createBST(root);
    levelOrderTraversal(root);
    cout<<endl;
        int x;
        cout<<"Find the successor of ";
        cin>>x;
        Node* ans1 = inOrderSuccessor(root,x);
        Node* ans2 = inOrderPredecessor(root,x);
        cout<<"Successor of"<< x <<"is "<<ans1->data<<endl;;
        cout<<"Predecessor of"<< x <<"is "<<ans2->data<<endl;;
}

// 5 3 7 2 4 6 9 1 8 10