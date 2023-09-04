// Determine if two trees are identical or not
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

bool isIdentical(Node* root1, Node* root2){
    if(root1 == NULL && root2 == NULL){
        return true;
    }
    if(root1 == NULL && root2 != NULL){
        return false;
    }
    if(root1 != NULL && root2 == NULL){
        return false;
    }
    if(root1->data != root2->data){
        return false;
    }
    bool left = isIdentical(root1->left,root2->left);
    bool right = isIdentical(root1->right,root2->right);

    if(left && right){
        return true;
    }else{
        return false;
    }
}

int main()
{
    Node* root1 = NULL;
    Node* root2 = NULL;
    cout<<"Build tree 1"<<endl;
    root1 = buildTree(root1);
    cout<<"Build tree 2"<<endl;
    root2 = buildTree(root2);
    if(isIdentical(root1,root2)){
        cout<<"Both trees are identical";
    }else{
        cout<<"Trees are not identical";
    }
    return 0;
}