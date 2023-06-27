#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    // Constructor
    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
    }

    // Insertion at beginning
    void insertAtBeginning(Node* &head, Node* &tail, int data){
        if(head == NULL){
            Node* temp = new Node(data);
            head = temp;
            tail = temp;
        }else{
            Node* temp = new Node(data);
            temp->next = head;
            head->prev = temp;
            head = temp;
        }
    }

    // Traversal
    void print(Node* &head){
        Node* temp = head;
        while(temp != NULL){
            cout<<temp->data<<" ";
            temp = temp->next;
        }
        cout<<endl;
    }

    // Get length of list
    int getLength(Node* &head){
        Node* temp = head;
        int cnt = 0;
        while(temp != NULL){
            cnt++;
            temp = temp->next;
        }
        return cnt;
    }

};

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    Node* operation;
    cout<<"Starting list : ";
    operation->print(head);
    cout<<"length of list : "<<operation->getLength(head)<<endl;
    operation->insertAtBeginning(head,tail,5);
    operation->print(head);
    operation->insertAtBeginning(head,tail,3);
    operation->print(head);
    cout<<"length of list : "<<operation->getLength(head)<<endl;
    return 0;
}