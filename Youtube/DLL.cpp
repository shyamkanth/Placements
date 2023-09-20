#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int val){
        this->data = val;
        this->next = NULL;
        this->prev = NULL;
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

void insertAtBeg(Node* &head, Node* &tail, int data){
    // Step 1: Create a new Node
    Node* newNode = new Node(data);

    // Step 2: Handle empty list case
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 3: Handle non-empty list case
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}

void insertAtEnd(Node* &head, Node* &tail, int data){
    // Step 1: Create a new Node
    Node* newNode = new Node(data);

    // Step 2: Handle empty list case
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 3: Non empty list handle
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

void insertAtPos(Node* &head, Node* &tail, int data, int pos){
    // Step 1
    Node* newNode = new Node(data);

    // Step 2:
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 3
    // Subcase 1
    if(pos == 1){
        insertAtBeg(head,tail,data);
        return;
    }

    // Subcase 2
    int len = length(head);
    if(pos == len+1){
        insertAtEnd(head,tail,data);
        return;
    }

    // Subcase 3
    Node* back = NULL;
    Node* front = head;
    int cnt = 1;
    while(cnt<pos){
        back = front;
        front = front->next;
        cnt++;
    }
    newNode->next = front;
    newNode->prev = back;
    back->next = newNode;
    front->prev = newNode;
}

void print(Node* head, Node* tail){
    if(head == NULL){
        cout<<"List is empty."<<endl;
        return;
    }
    Node* temp = head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
    cout<<"Head: "<<head->data<<endl;
    cout<<"Tail: "<<tail->data<<endl;
}



int main(){
    Node* head = NULL;
    Node* tail = NULL;

    insertAtBeg(head,tail,5);
    insertAtBeg(head,tail,4);

    insertAtEnd(head,tail,6);
    insertAtEnd(head,tail,7);

    insertAtPos(head,tail,1,1);
    insertAtPos(head,tail,8,6);
    insertAtPos(head,tail,2,2);
    insertAtPos(head,tail,3,3);
    print(head,tail);

    
}