// Count leaf Nodes
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

    cout<<"Enter left child of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter right child of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

void countLeafNode(Node* &root, int &cnt){
    if(root == NULL){
        return;
    }

    countLeafNode(root->left,cnt);
    if(root->left == NULL && root->right == NULL){
        cnt++;
    }
    countLeafNode(root->right,cnt);
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);

    int cnt = 0;
    countLeafNode(root,cnt);

    cout<<"Total leaf node is "<<cnt;
    return 0;
}