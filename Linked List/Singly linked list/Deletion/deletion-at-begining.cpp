#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    //Constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
};

void delFromBeg(Node* &head, Node* &tail){
    // step 1: Handle Empty list case
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    // Step 2: Handle Non empty list case
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
}

void insertAtBeginning(Node* &head,Node* &tail, int data){
    // Creation of new Node
    Node* newNode = new Node(data);

    // CHeck if the list is empty
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
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

    insertAtBeginning(head,tail,10);
    insertAtBeginning(head,tail,20);
    insertAtBeginning(head,tail,30);
    insertAtBeginning(head,tail,40);

    delFromBeg(head,tail);
    print(head,tail);
    
    return 0;
}