#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

// Find length of linked list
int getLength(Node* head){
    Node* temp = head;
    int len = 0;
    while(temp != NULL){
        temp = temp->next;
        len++;
    }
    return len;

}

// Get middle of linked list
Node* getMiddle(Node* head){
    int len = getLength(head);
    int mid = len/2;
    Node* temp = head;
    int cnt = 0;
    while(cnt<mid){
        temp = temp->next;
        cnt++;
    }
    return temp;
}

// Insertion
void insertAtBeginning(Node* &head,Node* &tail,int data){
    if(head == NULL){
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }else{
        Node* newNode = new Node(data);
        newNode->next = head;
        head = newNode;
    }
}

// Traversal
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtBeginning(head,tail,5);
    insertAtBeginning(head,tail,4);
    insertAtBeginning(head,tail,3);
    insertAtBeginning(head,tail,2);
    insertAtBeginning(head,tail,1);
    cout<<"starting list : ";
    print(head);
    Node* mid = getMiddle(head);
    cout<<"Middle = "<<mid->data;
    return 0;
}