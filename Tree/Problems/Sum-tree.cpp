// Sum Tree
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

pair<bool,int> isSumTree(Node* root){
    if(root == NULL){
        pair<bool,int> p = make_pair(true,0);
        return p;
    }
    if(root->left == NULL && root->right == NULL){
        pair<bool,int> p = make_pair(true,root->data);
        return p;
    }

    pair<bool,int> leftAns = isSumTree(root->left);
    pair<bool,int> rightAns = isSumTree(root->right);

    bool isLeftSumTree = leftAns.first;
    bool isRightSumTree = rightAns.first;

    int leftSum = leftAns.second;
    int rightSum = rightAns.second;

    bool sum = root->data == leftSum + rightSum;

    pair<bool,int> ans;
    if(isLeftSumTree && isRightSumTree && sum){
        ans.first = true;
        ans.second = 2*root->data;
    }else{
        ans.first = false;
    }
    return ans;
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);
    if(isSumTree(root).first){
        cout<<"It's a sum tree.";
    }else{
        cout<<"It is not a sum tree.";
    }
    return 0;
}