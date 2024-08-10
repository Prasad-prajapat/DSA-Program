#include<iostream>
#include<queue>
using namespace std;

class Node
{
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

Node* createTree(){
    cout<<"Enter the value for Node : ";
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }
    // step 1 - create Node
    Node* root = new Node(data);

    // step 2 - create left subtree
    root->left = createTree();

    // step 3 - create right suntree
    root->right = createTree();

    return root;
}

void preOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    // N L R
    cout<<root->data<<" ";
    preOrderTraversal(root->left);
    preOrderTraversal(root->right);
    
}

void InOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    // L
    InOrderTraversal(root->left);
    // N
    cout<<root->data<<" ";
    // R
    InOrderTraversal(root->right);
    
}

void postOrderTraversal(Node* root){
    if(root == NULL){
        return;
    }
    // L R N
    postOrderTraversal(root->left);
    postOrderTraversal(root->right);
    cout<<root->data<<" ";
    
}

void levelOrderTraversal(Node* root){
    queue<Node*>q;
    q.push(root);

    while(!q.empty()){
        Node* front = q.front();
        q.pop();
        cout<<front->data<<" ";
        
        if(front->left !=NULL){
            q.push(front->left);
        }
        if(front->right !=NULL){
            q.push(front->right);
        }
    } 
}

int main(){
    Node* root = createTree();

    // cout<<"printing preOrder : ";
    // preOrderTraversal(root);
    // cout<<endl;

    // cout<<"printing InOrder : ";
    // InOrderTraversal(root);
    // cout<<endl;

    // cout<<"printing postOrder : ";
    // postOrderTraversal(root);

    cout<<"printing LevelOrder : ";
    levelOrderTraversal(root);
}
