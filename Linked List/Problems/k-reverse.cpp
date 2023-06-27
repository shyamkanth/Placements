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

//Traversing the linked list
void print(Node* &head, Node* &tail){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

Node* kReverse(Node* head, int k){
    if(head == NULL){
        return NULL;
    }
    Node* prev = NULL;
    Node* next = NULL;
    Node* curr = head;
    int cnt = 0;
    
    while(curr!=NULL && cnt<k){
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
        cnt++;
    }

    if(next != NULL){
        head->next = kReverse(next,k);
    }
    return prev;
}

//Insertion at Beginning
void insertAtBegining(Node* &head,Node* &tail, int data){
    if(head==NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    Node* temp = new Node(data);
    temp->next = head;
    head =temp;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertAtBegining(head,tail,0);
    insertAtBegining(head,tail,2);
    insertAtBegining(head,tail,1);
    insertAtBegining(head,tail,3);
    print(head,tail);
    cout<<"after reversing : "<<endl;
    head = kReverse(head,2);
    print(head,tail);
    return 0;
}