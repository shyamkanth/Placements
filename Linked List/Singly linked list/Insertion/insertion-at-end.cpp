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


void insertionAtEnd(Node* &head, Node* &tail, int data){
    Node* newNode = new Node(data);

    if(head == NULL){
        head = newNode;
        tail = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
}

void print(Node* head, Node* tail){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertionAtEnd(head,tail,30);
    insertionAtEnd(head,tail,40);

    print(head,tail);

    return 0;
}