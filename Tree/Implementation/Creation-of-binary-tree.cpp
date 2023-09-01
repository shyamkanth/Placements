// Creation of binary tree
// Shyam Sunder Kanth
// Insta : still_23.6_8

#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this->data =data;
        this->left = NULL;
        this->right = NULL;
    }
};

Node* buildTree(Node* root){
    cout<<"Enter data:";
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

int main()
{
    Node* root = NULL;

    root = buildTree(root);
    return 0;
}