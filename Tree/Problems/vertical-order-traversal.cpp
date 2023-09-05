// Vertical order traversal
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

vector<int> verticalOrderTraversal(Node* root){
    map<int,map<int,vector<int>>> nodes;
    queue<pair<Node*,pair<int,int>>> q;
    vector<int> ans;

    if(root == NULL){
        return ans;
    }

    q.push(make_pair(root,make_pair(0,0)));

    while (!q.empty())
    {
        pair<Node*, pair<int,int>> temp = q.front();
        q.pop();
        Node* frontNode = temp.first;
        int hd = temp.second.first;
        int lvl = temp.second.second;

        nodes[hd][lvl].push_back(frontNode->data);

        if(frontNode->left){
            q.push(make_pair(frontNode->left,make_pair(hd-1,lvl+1)));
        }
        if(frontNode->right){
            q.push(make_pair(frontNode->right, make_pair(hd+1,lvl+1)));
        }
    }

    for(auto i : nodes){
        for(auto j : i.second){
            for(auto k : j.second){
                ans.push_back(k);
            }
        }
    }

    return ans;
    
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);
    vector<int> res = verticalOrderTraversal(root);
    cout<<"\nVertical order traversal is ";
    for(auto i:res){
        cout<<i<<" ";
    }
    return 0;
}