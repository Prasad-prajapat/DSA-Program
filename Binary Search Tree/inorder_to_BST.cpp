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

Node* convertinorderToBST(int inOrder[],int s,int e){
    // Base case
    if(s > e){
        return NULL;
    }

    int mid = (s+e)/2;
    int element = inOrder[mid];
    Node* root = new Node(element);

    root->left = convertinorderToBST(inOrder,s,mid-1);
    root->right = convertinorderToBST(inOrder,mid+1,e);
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
    int arr[] = {10,20,30,40,50,60,70};
    int size = 7;
    Node* root = convertinorderToBST(arr,0,size-1);
    levelOrderTraversal(root);
}