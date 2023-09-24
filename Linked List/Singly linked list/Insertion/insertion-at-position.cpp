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

int length(Node* head){
    Node* temp = head;
    int cnt = 1;
    while(temp->next != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
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

void insertAtPosition(Node* &head, Node* &tail, int data, int pos){
    // Step 1
    Node* newNode = new Node(data);

    // Step 2
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 3
    // Case 1 : Insert at beginning
    if(pos == 1){
        insertAtBeginning(head, tail, data);
        return;
    }

    // Case 2 : insert at end
    int len = length(head);
    if(pos == len+1){
        insertionAtEnd(head, tail, data);
        return;
    }

    // Case 3: any random position
    Node* previous = NULL;
    Node* front = head;
    int cnt = 1;
    while(cnt<pos){
        previous = front;
        front = front->next;
        cnt++;
    }
    newNode->next = front;
    previous->next = newNode;
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

    insertionAtEnd(head,tail,30);

    insertAtPosition(head,tail,5,1);
    insertAtPosition(head,tail,40,5);
    insertAtPosition(head,tail,25,4);
    
    print(head,tail);

    return 0;
}