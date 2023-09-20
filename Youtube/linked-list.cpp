
// Shyam Sunder Kanth
// Insta : still_23.6_8

#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

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

int length(Node* head){
    Node* temp = head;
    int cnt = 1;
    while(temp->next != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
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

void delFromEnd(Node* &head, Node* &tail){
    // Step 1: EMpty list
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    // Step 2: Non-empty list
    Node* temp = head;
    while(temp->next != tail){
        temp = temp->next;
    }
    tail = temp;
    temp->next = NULL;
}

void delFromPos(Node* &head, Node* &tail, int pos){
    // Case 1: handle empty list case
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    // Case 2: Non-empty list handle karo
    // Subcase 1: Deletion from beginning case
    if(pos == 1){
        delFromBeg(head,tail);
        return;
    }

    // Subcase 2: Deletion from end case
    int len = length(head);
    if(pos == len){
        delFromEnd(head,tail);
        return;
    }

    // Subcase 3: Any random position
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;
    while(cnt<pos){
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    prev->next = curr->next;
    curr->next = NULL;
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
    cout<<"Befor Deletion"<<endl;
    print(head,tail);

    // delFromBeg(head,tail);
    // delFromBeg(head,tail);

    // delFromEnd(head,tail);
    // delFromEnd(head,tail);
    delFromPos(head,tail,1);
    delFromPos(head,tail,5);
    delFromPos(head,tail,3);
    cout<<"After Deletion"<<endl;
    print(head,tail);

    return 0;
}