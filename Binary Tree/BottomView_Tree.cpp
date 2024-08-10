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

void printBottomView(Node* root){
    map<int,int>hdToNodemap;
    queue<pair<Node*,int>>q;
    // intially queue is empty
    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int>temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

    // override the map entry
        hdToNodemap[hd] = frontNode->val;

        if(frontNode->left != NULL){
            q.push(make_pair(frontNode->left,hd-1));
        }

        if(frontNode->right != NULL){
            q.push(make_pair(frontNode->right,hd+1));
        }
    }

    cout<<"printing Bottom View :"<<endl;
    for(auto i : hdToNodemap){
        cout<<i.second<<" ";
    }
}

int main(){
    Node* root = createTree();
    printBottomView(root);

}

//  10 20 40 -1 -1 50 70 110 -1 -1 111 -1 -1 80 -1 -1 30 -1 60 -1 90 112 -1 -1 113 -1 -1