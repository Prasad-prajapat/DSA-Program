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

Node* insertToBST(Node* root , int x){
    if(root == NULL){
        root = new Node(x);
        return root;
    }
    if(root->data < x){
        root->right = insertToBST(root->right,x);
    }
    else{
        root->left = insertToBST(root->left,x);
    }
    return root;
}

void createBST(Node* &root){
    cout<<"Enter the data"<<" ";
    int x;
    cin>>x;

    while(x!=-1){
        root = insertToBST(root,x);
        // cout<<"Enter the data"<<" ";
        cin>>x;
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
            
            if(front->left !=NULL){
                q.push(front->left);
            }
            if(front->right !=NULL){
                q.push(front->right);
            }
        }
    } 
}

Node* minValue(Node* root){
    if(root == NULL){
        cout<<"Min value not exist"<<endl;
    }
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){
    if(root == NULL){
        cout<<"Max value not exist"<<endl;
    }
    Node* temp =root;
    while(temp->right !=NULL){
        temp = temp->right;
    }
    return temp;
}

bool searchBST(Node* root,int target){
    if(root == NULL){
        return false;
    }
    if(root->data == target){
        return true;
    }
    bool leftAns = false;
    bool rightAns = false;

    if(root->data < target){
        rightAns = searchBST(root->right,target);
    }
    else{
        leftAns = searchBST(root->left,target);
    }
    return leftAns || rightAns;

}

int main(){
    Node* root = NULL;
    createBST(root);
    levelOrderTraversal(root);
    cout<<endl;
    Node* min = minValue(root);
    Node* max = maxValue(root);
    cout<<"Minimum value of BST : "<<min->data<<endl;
    cout<<"Maximum value of BST : "<<max->data<<endl;

    int target;
    cout<<"Enter the target"<<" ";
    cin>>target;
    bool ans = searchBST(root,target);
    cout<<ans;
}

// 50 30 60 25 40 70 80 55