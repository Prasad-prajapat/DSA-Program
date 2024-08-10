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

void kthAncestor(Node* root, int target, int k, vector<int> v){
    if(root == NULL){
        return;
    }
    v.push_back(root->data);

    if(root->data == target){
        while(k--){
            v.pop_back();
        }
        int x = v.size();
        cout<<v[x-1]<<endl;
        return;
    }
    kthAncestor(root->left, target, k,v);
    kthAncestor(root->right, target, k ,v);
}



int main(){
    Node* root = createTree();

    vector<int>ans;
    int target = 100;
    int k = 2;
    kthAncestor(root,target, k ,ans);


    // int x = ans.size();
    // cout<<ans[x-1]<<endl;



}

// 10 20 40 70 -1 -1 80 90 -1 -1 100 -1 -1 50 -1 -1 30 -1 60 -1 -1