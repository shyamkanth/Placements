#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

    void print(Node* &head){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
    }

    void insertionAtBegining(Node* &head, int data){
        Node* temp = new Node(data);
        temp->next = head;
        head = temp;
    }

    
    void insertionAtEnd(Node* &tail, int data){
        Node* temp = new Node(data);
        tail->next = temp;
        tail = temp;
    }

    void insertionAtPosition(Node* &head,int position, int data){
        Node* temp = head;
        int cnt = 1;
        while(cnt<position-1){
            temp = temp->next;
            cnt++;
        }
        Node* nodeToInsert = new Node(data);
        nodeToInsert->next = temp->next;
        temp->next = nodeToInsert;
    }
};


int main()
{
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* tail = node1;
    Node* operation;

    operation->insertionAtEnd(tail,15);
    operation->insertionAtBegining(head,5);
    operation->insertionAtPosition(head,4,25);
    operation->insertionAtPosition(head,4,20);
    operation->print(head);
    
    return 0;
}