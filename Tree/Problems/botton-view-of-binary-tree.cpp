// Bottom view of Binary tree
// Shyam Sunder Kanth
// Insta : still_23.6_8

#include<iostream>
#include<vector>
#include<queue>
#include<map>

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

vector<int> bottomView(Node* root){
    vector<int> ans;
    if(root == NULL){
        return ans;
    }

    map<int,int> bottomNode;
    queue<pair<Node*, int>> q;

    q.push(make_pair(root,0));

    while(!q.empty()){
        pair<Node*,int> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second;

        bottomNode[hd] = frontNode->data;

        if(frontNode->left){
            q.push(make_pair(frontNode->left, hd-1));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, hd+1));
        }
    }

    for(auto i : bottomNode){
        ans.push_back(i.second);
    }

    return ans;
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);
    vector<int> res = bottomView(root);
    cout<<"\nBottom view of this tree is : ";
    for(auto i : res){
        cout<<i<<" ";
    }
    return 0;
}