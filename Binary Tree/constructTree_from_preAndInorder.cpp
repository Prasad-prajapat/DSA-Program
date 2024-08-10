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


// int search(int inOrder[],int element,int size){
//     for(int i=0;i<size;i++){
//         if(inOrder[i] == element){
//             return i;
//         }
//     }
//     return -1;
// }

Node* constructTreeFrompreOrderToinOrder(int preOrder[],int inOrder[],int &preOrderIndex,int inOrderStart,int inOrderEnd,int size, map<int,int> &valueToIndexMap){
    // Base case
    if(preOrderIndex >= size || inOrderStart > inOrderEnd){
        return NULL;
    }

    int element = preOrder[preOrderIndex];
    preOrderIndex++;

    Node* root = new Node(element);

    // int position = search(inOrder,element,size);
    int position = valueToIndexMap[element];
    root->left = constructTreeFrompreOrderToinOrder(preOrder,inOrder,preOrderIndex,inOrderStart,position-1,size,valueToIndexMap);

    root->right = constructTreeFrompreOrderToinOrder(preOrder,inOrder,preOrderIndex,position+1,inOrderEnd,size,valueToIndexMap);

    return root;
}

void createMappeing(int inOrder[],int size,map<int,int> &valueToIndexMap){
    for(int i=0;i<size;i++){
        int ele = inOrder[i];
        int index = i;
        valueToIndexMap[ele] = index;
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
            cout<<front->val<<" ";
            
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
    int inOrder[] = {10,8,6,2,4,12};
    int preOrder[] = {2,8,10,6,4,12};
    int preOrderIndex = 0;
    int inOrderStart = 0;
    int inOrderEnd = 5;
    int size = 6;

    map<int,int>valueToIndexMap;
    createMappeing(inOrder,size,valueToIndexMap);

    Node* root = constructTreeFrompreOrderToinOrder(preOrder,inOrder,preOrderIndex,inOrderStart,inOrderEnd,size,valueToIndexMap);

    levelOrderTraversal(root);
}