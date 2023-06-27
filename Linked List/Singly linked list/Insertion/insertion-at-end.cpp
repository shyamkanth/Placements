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


//Insertion at end
void insertionAtend(Node* &tail, int data){
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
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
    Node* tail = node1;
    print(head);
    insertionAtend(tail,2);
    print(head);
    insertionAtend(tail,3);

    print(head);

    return 0;
}