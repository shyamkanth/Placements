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

// Get Middle
Node* getMiddle(Node* head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    if(head->next->next == NULL){
        return head->next;
    }
    Node* node1 = head;
    Node* node2 = head->next;

    while(node2 != NULL){
        node2 = node2->next;
        if(node2 != NULL){
            node2 = node2->next;
        }
        node1 = node1->next;
    }
    return node1;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtBeginning(head,tail,6);
    insertAtBeginning(head,tail,5);
    insertAtBeginning(head,tail,4);
    insertAtBeginning(head,tail,3);
    insertAtBeginning(head,tail,2);
    insertAtBeginning(head,tail,1);
    cout<<"starting list : ";
    print(head);
    Node* mid = getMiddle(head);
    cout<<"Middle : "<<mid->data;
    return 0;
}