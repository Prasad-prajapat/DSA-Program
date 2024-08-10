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
    // cout<<"Enter the value for Node : ";
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

bool solve(Node* root, int targetSum,int sum){
    if(root == NULL){
        return false;
    }
    sum += root->data;
    if(root->left == NULL && root->right == NULL){
        if(targetSum == sum){
            return true;
        }
        else{
            return false;
        }
    }
    bool leftAns = solve(root->left,targetSum,sum);
    bool rightAns = solve(root->right,targetSum,sum);
    return leftAns || rightAns;
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
    Node* root = createTree();

    levelOrderTraversal(root);
    cout<<endl;

    int targetSum = 27;
    int sum = 0;
    bool ans = solve(root,targetSum,sum);
    cout<<ans;
}
// 1 2 4 6 -1 -1 7 -1 -1 -1 3 -1 5 20 -1 -1 10 -1 8 -1 -1