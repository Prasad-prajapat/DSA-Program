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
    cout<<"Enter the data"<<" ";
    int data;
    cin>>data;
    while(data!=-1){
        root = insertToBST(root,data);
        cin>>data;
    }
}

Node* maxValue(Node* root){
    if(root == NULL){
        cout<<"Maximum value not possible"<<endl;
    }
    while(root->left!=NULL){
        root = root->left;
    }
    return root;
}

Node* deleteFromBST(Node* root,int target){
    if(root == NULL){
        return NULL;
    }

    if(root->data == target){
        if(root->left == NULL && root->right ==NULL){
            delete root;
            return NULL;
        }
        else if(root->left != NULL && root->right == NULL){
            Node* leftSubtree = root->left;
            delete root;
            return leftSubtree;
        }
        else if(root->left == NULL && root->right != NULL){
            Node* rightSubtree = root->right;
            delete root;
            return rightSubtree;
        }
        else{
            Node* maxi = maxValue(root->left);
            // replacement
            root->data = maxi->data;
            root->left = deleteFromBST(root->left,maxi->data);
            return root;
        }
    }
    else if(root->data < target){
        root->right = deleteFromBST(root->right,target);
    }
    else{
        root->left = deleteFromBST(root->left,target);
    }
    return root;
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
            
            if(front->left !=NULL){
                q.push(front->left);
            }
            if(front->right !=NULL){
                q.push(front->right);
            }
        }
    } 
}

int main(){
    Node* root = NULL;
    createBST(root);
    levelOrderTraversal(root);
    cout<<endl;

     int target;
    while(target!=-1){
        cout<<"Enter the target"<<" "; 
        cin>>target;
        root = deleteFromBST(root,target);
        levelOrderTraversal(root);
    }
}