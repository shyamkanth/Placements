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

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

Node* reverse(Node* head){
    // Base case
    if(head == NULL || head->next == NULL){
        return head;
    }

    Node* tempHead = reverse(head->next);
    head->next->next = head;
    head->next = NULL;

    return tempHead;
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
    cout<<"reversed list : ";
    head = reverse(head);
    print(head);
    return 0;
}