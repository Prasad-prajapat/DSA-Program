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

bool isIdentical(Node*p,Node*q){
    if(!p && !q){
        return true;
    }
    if(p && q){  
        return (p->data == q->data &&
                isIdentical(p->left,q->left)&&
                isIdentical(p->right,q->right));
    }  
    return false;
}

// bool isIdentical(Node* p,Node*q){
//     if(!p && !q){
//         return true;
//     }
//     if(p && q){
//         if(p->data == q->data){
//             bool leftAns = isIdentical(p->left,q->left);
//             bool rightAns = isIdentical(p->right,q->right);
//             return leftAns && rightAns;
//         }
//     }
//     return false;
// }

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
    Node* root1 = createTree();
    levelOrderTraversal(root1);

    cout<<endl;
    Node* root2 = createTree();
    levelOrderTraversal(root2);
    bool ans = isIdentical(root1,root2);
    cout<<ans;
}