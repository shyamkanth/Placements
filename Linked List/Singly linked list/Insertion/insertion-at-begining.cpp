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


//Insertion at begining
void insertAtBegining(Node* &head, int data ){
    Node* temp = new Node(data);
    temp->next = head;
    head = temp;
}

// Traversing the list
void print(Node* &head){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
}

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    insertAtBegining(head,12);
    insertAtBegining(head,15);
    print(head);
    return 0;
}