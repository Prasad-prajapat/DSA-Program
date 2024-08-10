#include<iostream>
#include<queue>
#include<map>
using namespace std;

class Node{
    public:
        int val;
        Node* left;
        Node* right;

        Node(int val){
            this->val = val;
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

void printrightView(Node* root,int level,vector<int> &v){
    if(root == NULL){
        return;
    }

    if(level == v.size()){
        v.push_back(root->val);
    }
    printrightView(root->right, level+1, v);
    printrightView(root->left, level+1, v);
}

int main(){
    Node* root = createTree();
    int level = 0;
    vector<int> v;
    printrightView(root,level,v);

    for(auto i : v){
        cout<< i <<" ";
    }
}

// 10 30 61 -1 -1 60 62 -1 -1 -1 20 50 -1 65 -1 69 -1 -1 40 -1 -1

