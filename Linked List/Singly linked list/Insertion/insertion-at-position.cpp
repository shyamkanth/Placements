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

//Insertion at position
void insertAtPosition(Node* &head, int position, int data){
    Node* temp = head;
    int cnt =1;
    while(cnt<position-1){
        temp = temp->next;
        cnt++;
    }
    Node* nodeToInsert = new Node(data);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

//Traversing the linked list
void print(Node* head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
}

int main()
{
    Node* node1 = new Node(1);
    Node* head = node1;
    print(head);
    insertAtPosition(head,2,2);
    print(head);
    insertAtPosition(head,3,3);
    print(head);

    return 0;
}