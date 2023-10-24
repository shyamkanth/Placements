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

void delFromBeg(Node* &head, Node* &tail){
    // Step 1:Empty list case
    if(head == NULL){
        cout<<"List is empty";
        return;
    }

    // Step 2: Handle non empty list case
    head = head->next;
    head->prev->next = NULL;
    head->prev = NULL;
}

void delFromEnd(Node* &head, Node* &tail){
    // Step 1: Empty list
    if(head == NULL){
        cout<<"List is empty";
        return;
    }

    // Step 2: Non empty list
    tail = tail->prev;
    tail->next->prev = NULL;
    tail->next = NULL;
}

void delFromPos(Node* &head, Node* &tail, int pos){
    // Step 1: Handle empty list case
    if(head == NULL){
        cout<<"List is empty";
        return;
    }

    // Step 2: Handle non-empty list case
    // case 1: Deletion at beginning
    if(pos == 1){
        delFromBeg(head,tail);
        return;
    }

    // Case 2: Deletion from end
    int len = length(head);
    if(pos == len){
        delFromEnd(head,tail);
        return;
    }

    // Case 3: Any random position
    Node* back = NULL;
    Node* curr = head;
    int cnt = 1;
    while(cnt<pos){
        back = curr;
        curr = curr->next;
        cnt++;
    }
    back->next = curr->next;
    curr->next->prev = back;
    curr->prev = NULL;
    curr->next = NULL;
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

    // delFromBeg(head,tail);
    // delFromBeg(head,tail);

    // delFromEnd(head,tail);
    // delFromEnd(head,tail);

    delFromPos(head,tail,1);
    delFromPos(head,tail,7);
    delFromPos(head,tail,3);
    delFromPos(head,tail,4);
    print(head,tail);

    
}