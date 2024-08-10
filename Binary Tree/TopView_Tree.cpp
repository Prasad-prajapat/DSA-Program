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
   
    int data;
    cin>>data;

    if(data == -1){
        return NULL;
    }
    
    Node* root = new Node(data);
    root->left = createTree();
    root->right = createTree();
    return root;
}

void printTopView(Node* root){
    map<int,int>hdToNodemap;
    queue<pair<Node*,int>>q;
    // intially queue is empty
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int>temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

    // if there is no entry in map
        if(hdToNodemap.find(hd) == hdToNodemap.end()){
            hdToNodemap[hd] = frontNode->val;
        }

        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left,hd-1));
        }

        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    cout<<"printing Top View :"<<endl;
    for(auto i : hdToNodemap){
        cout<<i.second<<" ";
    }
}

int main(){
    Node* root = createTree();
    printTopView(root);

}