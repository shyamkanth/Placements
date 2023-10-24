// Shyam Sunder Kanth
// Insta : still_23.6_8

#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        this->data = val;
        this->prev = this;
        this->next = this;
    }
};

int length(Node* head, Node* tail){
    Node* temp = head;
    int cnt = 1;
    while(temp != tail){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

void insert(Node* &head, Node* &tail, int data, int pos){
    // Step 1: creation of newNode
    Node* newNode = new Node(data);

    // Step 2: Handle empty list case
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 3: Handle non empty list case
    // Sub-1 : insert at beg
    if(pos == 1){
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        head = newNode;
        return;
    }

    // Sub-2 : insert at end
    int len = length(head,tail);
    if(pos == len+1){
        newNode->next = head;
        newNode->prev = tail;
        head->prev = newNode;
        tail->next = newNode;
        tail = newNode;
        return;
    }

    // Sub-3 : insert at any pos
    Node* p1 = NULL;
    Node* p2 = head;
    int cnt = 1;
    while(cnt < pos){
        p1 = p2;
        p2 = p2->next;
        cnt++;
    }
    newNode->next = p2;
    newNode->prev = p1;
    p1->next = newNode;
    p2->prev = newNode;
}

void deletion(Node* &head, Node* &tail, int pos){
    // Step 1: EMpty list
    if(head == NULL){
        cout<<"List is empty";
        return;
    }

    // Step 2: Non empty list
    // Sub-1 : beginning
    if(pos == 1){
        Node* temp = head;
        head = head->next;
        tail->next = head;
        head->prev = tail;
        temp->next = NULL;
        temp->prev = NULL;

        return;
    }

    // Sub-2
    int len = length(head,tail);
    if(pos == len){
        Node* temp = tail;
        tail = tail->prev;
        tail->next = head;
        head->prev = tail;
        temp->prev = NULL;
        temp->next = NULL;

        return;
    }

    Node* p1 = NULL;
    Node* p2 = head;
    int cnt = 1;
    while(cnt<pos){
        p1 = p2;
        p2 = p2->next;
        cnt++;
    }
    p1->next = p2->next;
    p2->next->prev = p1;
    p2->prev = NULL;
    p2->next = NULL;
}

void print(Node* head){
    if(head == NULL){
        cout<<"List is empty";
        return;
    }
    Node* temp = head;
    cout<<temp->data<<" ";
    while(temp->next != head){
        temp = temp->next;
        cout<<temp->data<<" ";
    }
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insert(head,tail,5,10);
    insert(head,tail,4,1);
    insert(head,tail,6,3);
    insert(head,tail,7,4);
    insert(head,tail,10,3);
    insert(head,tail,20,2);

    deletion(head,tail,1);
    deletion(head,tail,5);
    deletion(head,tail,3);
    deletion(head,tail,2);


    print(head);


    return 0;
}