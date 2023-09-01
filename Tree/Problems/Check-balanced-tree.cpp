// Check balanced tree
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

pair<bool,int> isBalanced(Node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }

    pair<bool,int> left = isBalanced(root->left);
    pair<bool,int> right = isBalanced(root->right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second-right.second)<=1;

    pair<bool,int> ans;
    ans.second = left.second + right.second + 1;
    if(leftAns && rightAns && diff){
        ans.first = true;
    }else{
        ans.first = false;
    }
    return ans;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    if(isBalanced(root).first){
        cout<<"Tree is balanced";
    }else{
        cout<<"Tree is unbalanced";
    }
}