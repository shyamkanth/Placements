// Build tree from level order
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

void buildFromLevelOrder(Node* &root){
    queue<Node*> q;

    cout<<"Enter root node : ";
    int data;
    cin>>data;
    root = new Node(data);
    q.push(root);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        cout<<"Enter left child of "<<temp->data<<endl;
        int leftChild;
        cin>>leftChild;
        if(leftChild!=-1){
            temp->left = new Node(leftChild);
            q.push(temp->left);
        }

        cout<<"Enter right child of "<<temp->data<<endl;
        int rightChild;
        cin>>rightChild;
        if(rightChild!=-1){
            temp->right = new Node(rightChild);
            q.push(temp->right);
        }
    }
}

void levelOrderTraversal(Node* root){
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* temp = q.front();
        q.pop();
        cout<<temp->data<<" ";

        if(temp->left!= NULL){
            q.push(temp->left);
        }

        if(temp->right!=NULL){
            q.push(temp->right);
        }
    }
    
}

int main()
{
    Node* root = NULL;
    buildFromLevelOrder(root);
    cout<<"Level order traversal is : "<<endl;
    levelOrderTraversal(root);
    return 0;
}