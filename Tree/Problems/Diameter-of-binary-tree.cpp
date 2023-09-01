// Diameter of binary tree
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

pair<int,int> diameter(Node* root){
    if(root == NULL){
        pair<int,int> p = make_pair(0,0);
        return p;
    }

    pair<int,int> left = diameter(root->left);
    pair<int,int> right = diameter(root->right);

    int ans1 = left.first;
    int ans2 = right.first;
    int ans3 = left.second+right.second+1;

    pair<int,int> ans;
    ans.first = max(ans1,max(ans2,ans3));
    ans.second = max(left.second, right.second) + 1;

    return ans;
}

int main(){
    Node* root = NULL;
    root = buildTree(root);

    cout<<"Diameter of this Binary tree is : ";
    cout<<diameter(root).first;
}