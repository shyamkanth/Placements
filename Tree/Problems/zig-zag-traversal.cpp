// Zig Zag / Spiral traversal
// Shyam Sunder Kanth
// Insta : still_23.6_8

#include<iostream>
#include<vector>
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

    cout<<"Enter left child of "<<data<<endl;
    root->left = buildTree(root->left);
    cout<<"Enter right child of "<<data<<endl;
    root->right = buildTree(root->right);

    return root;
}

vector<int> zigZag(Node* root){
    vector<int> result;
    if(root == NULL){
        return result;
    }

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(!q.empty()){
        int size = q.size();
        vector<int> temp(size);

        for(int i =0;i<size;i++){
            Node* front = q.front();
            q.pop();

            int index = leftToRight ? i : size-i-1;
            temp[index]= front->data;

            if(front->left){
                q.push(front->left);
            }
            if(front->right){
                q.push(front->right);
            }
        }
        leftToRight = !leftToRight;
        for(auto i : temp){
            result.push_back(i);
        }
    }

    return result;
}

int main()
{
    Node* root = NULL;
    root = buildTree(root);
    vector<int> zigZagtraversal = zigZag(root);
    cout<<"\nZig Zag traversal is : "<<endl;
    for(auto i:zigZagtraversal){
        cout<<i<<" ";
    }
    return 0;
}