// Level order traversal of binary tree
// Shyam Sunder Kanth
// Insta : still_23.6_8

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

Node* buildTree(Node* root){
    cout<<"Enter data : ";
    int data;
    cin>>data;

    root = new Node(data);

    if(data == -1){
        return NULL;
    }

    cout<<"Enter the left child of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter the right child of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void levelOrderTraversal(Node* root){
    if(root == NULL){
        cout<<"tree is empty"<<endl;
        return;
    }
    queue<Node*> q;
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        cout<<temp->data<<" ";
        q.pop();

        if(temp->left != NULL){
            q.push(temp->left);
        }

        if(temp->right != NULL){
            q.push(temp->right);
        }
    }
}

int main()
{
    Node* root = NULL;

    root = buildTree(root);

    cout<<"Level order traversal is : ";
    levelOrderTraversal(root);

    return 0;
}