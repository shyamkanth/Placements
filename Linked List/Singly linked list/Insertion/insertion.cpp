#include<iostream>

using namespace std;

//Implementation of Node
class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

//Traversing the linked list
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

//Insertion at Beginning
void insertAtBegining(Node* &head, int data){
    Node* temp = new Node(data);
    temp->next = head;
    head =temp;
}

//Insertion at End
void insertAtEnd(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

//Insertion at Position
void insertAtPosition(Node* &head, int position, int data){
    Node* temp = head;
    int cnt = 1;
    while(cnt < position-1){
        temp = temp->next;
        cnt++;
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

int main()
{
    Node* node1 = new Node(1);
    Node* head = node1;
    Node* tail = node1;
    print(head);
    insertAtBegining(head,0);
    print(head);
    insertAtEnd(tail,2);
    print(head);
    insertAtPosition(head,4,3);
    print(head);
    return 0;
}