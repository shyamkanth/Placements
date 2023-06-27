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

    //Destructor
    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for the Node with data "<<value<<". New list is : "<<endl;
    }

    // Deletion at Any Position
    void deletionAtPosition(Node* &head, int position){
        Node* curr = head;
        Node* prev = NULL;
        int cnt = 1;
        while(cnt<position){
            prev = curr;
            curr = curr->next;
            cnt++;
        }
        prev->next = curr->next;
        curr->next = NULL;
        delete curr;
    }

    // Insertion at Begining
    void insertionAtBegining(Node* &head, int data){
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    // Traversal
    void print(Node* &head){
        Node* temp = head;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }
};

int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* operation;
    operation->print(head);
    operation->insertionAtBegining(head,9);
    operation->insertionAtBegining(head,8);
    operation->insertionAtBegining(head,7);
    operation->insertionAtBegining(head,6);
    operation->insertionAtBegining(head,5);
    operation->print(head);
    operation->deletionAtPosition(head,4);
    operation->print(head);
    return 0;
}