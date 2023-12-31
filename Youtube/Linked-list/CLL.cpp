#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next= this;
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
    // Step 1: Creation of new Node
    Node* newNode = new Node(data);

    // Step 2: Empty list handle
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 3: Non-empty list handle
    // Sub-1
    if(pos == 1){
        newNode->next = head;
        tail->next = newNode;
        head =newNode;
        return;
    }

    // Sub-2
    int len = length(head, tail);
    if(pos == len+1){
        newNode->next = head;
        tail->next = newNode;
        tail =newNode;
        return;
    }

    // Sub-3
    Node* back = NULL;
    Node* front = head;
    int cnt = 1;
    while(cnt<pos){
        back = front;
        front = front->next;
        cnt++;
    }
    newNode->next = front;
    back->next = newNode;
}

void deletion(Node* &head, Node* &tail, int pos){
    // Step 1: Handle empty list case
    if(head == NULL){
        cout<<"List is empty";
        return;
    }

    // Step 2: Handle non empty list case
    // Sub-1
    if(pos == 1){
        tail->next = head->next;
        head->next = NULL;
        head = tail->next;
        return;
    }

    // Sub-2
    int len = length(head,tail);
    if(pos == len){
        Node* temp = head;
        while(temp->next != tail){
            temp =temp->next;
        }
        temp->next = head;
        tail->next = NULL;
        tail = temp;
        return;
    }

    // Sub-3
    Node* back = NULL;
    Node* front = head;
    int cnt=1;
    while(cnt<pos){
        back = front;
        front = front->next;
        cnt++;
    }
    back->next = front->next;
    front->next = NULL;
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

    insert(head,tail,4,7);
    insert(head,tail,2,1);
    insert(head,tail,8,3);
    insert(head,tail,6,3);
    insert(head,tail,10,5);
    insert(head,tail,12,6);

    deletion(head,tail,1);
    deletion(head,tail,5);
    deletion(head,tail,3);
    print(head);

    return 0;
}