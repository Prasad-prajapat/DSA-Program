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
        return NULL;
    }
    Node* temp = root;
    while(temp->left != NULL){
        temp = temp->left;
    }
    return temp;
}

Node* maxValue(Node* root){
    if(root == NULL){
        return NULL;
    }
    Node* temp =root;
    while(temp->right !=NULL){
        temp = temp->right;
    }
    return temp;
}

bool solve(Node* root,int lwb,int upb){
    // base case
    if(root == NULL){
        return true;
    }
    bool cond1 = root->data > lwb;
    bool cond2 = root->data < upb;
    bool leftAns = solve(root->left,lwb,root->data);
    bool rightAns = solve(root->right,root->data,upb);

    if(cond1 && cond2 && leftAns && rightAns){
        return true;
    }
    else{
        return false;
    }
}

bool isvalidBST(Node* root){
    int lowerbound = INT_MIN;
    int upperbound = INT_MAX;

    bool ans = solve(root,lowerbound,upperbound);
    return ans;
}
// bool checkBST(Node* root){
//     if(root == NULL){
//         return true;
//     }
//     if(root->left == NULL && root->right == NULL){
//         return true;
//     }

//     Node* max = maxValue(root->left);
//     Node* min = minValue(root->right);

//     bool rleft = root->data > max->data ? true:false;
//     bool rright = root->data < min->data ? true:false; 

//     bool leftAns = checkBST(root->left);
//     bool rightAns = checkBST(root->right);

//     if(leftAns && rightAns && rleft && rright){
//         return true;
//     }
//     else{
//         return false;
//     }
    
// }

int main(){
    Node* root = NULL;
    createBST(root);
    levelOrderTraversal(root);
    bool ans = isvalidBST(root);
    cout<<ans;


}