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

    // Destructor
    ~Node(){
        int value = this->data;
        if(this->next!=NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"Memory is free for data : "<<value<<endl;
    }

    // Insertion at any position
    void insertAtPosition(Node* &head, Node* &tail, int position, int data){
        if(head == NULL){
            Node* temp = new Node(data);
            head = temp;
            tail = temp;
        }else{
            Node* temp = head;
            int cnt = 1;
            while(cnt<position-1){
                temp = temp->next;
                cnt++;
            }
            Node* nodeToInsert = new Node(data);
            nodeToInsert->next = temp->next;
            nodeToInsert->prev = temp;
            temp->next = nodeToInsert;
            tail = nodeToInsert;
        }
    }

   
    // Traversal
    void print(Node* &head){
        if(head == NULL){
            cout<<"List is empty";
        }else{
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
    }

    // Deletion from beginning
    void deletionAtBeginning(Node* &head,Node* &tail){
        if(head == NULL){
            cout<<"List is empty";
        }else{
            Node* temp = head;
            temp->next->prev = NULL;
            head = temp->next;
            temp->next = NULL;
            delete temp;
        }
    }

    // Deletion from end
    void deletionAtEnd(Node* &head, Node* &tail){
        if(head==NULL){
            cout<<"List is empty.";
        }else{
            Node* temp = tail;
            tail = temp->prev;
            temp->prev = NULL;
            tail->next = NULL;
            delete temp;
        }
    }

    // deletion from position
    void deleteAtPosition(Node* &head,Node* &tail, int position){
        if(position==1){
            deletionAtBeginning(head,tail);
            return;
        }
        if(head == NULL){
            cout<<"List is empty.";
        }else{
            Node* current = head;
            Node* previous = NULL;
            int cnt = 1;
            while(cnt<position){
                previous = current;
                current = current->next;
                cnt++;
            }
            if(current->next==NULL){
                deletionAtEnd(head,tail);
                return;
            }
            current->prev = NULL;
            previous->next = current->next;
            current->next->prev = previous;
            current->next = NULL;
            delete current;
        }
    }
};

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    Node* operation;
    operation->insertAtPosition(head,tail,1,1);
    operation->print(head);
    cout<<"head :"<<head->data<<" Tail :"<<tail->data<<endl;
    operation->insertAtPosition(head,tail,2,2);
    operation->print(head);
    cout<<"head :"<<head->data<<" Tail :"<<tail->data<<endl;
    operation->insertAtPosition(head,tail,3,3);
    operation->print(head);
    cout<<"head :"<<head->data<<" Tail :"<<tail->data<<endl;
    operation->insertAtPosition(head,tail,4,4);
    operation->print(head);
    cout<<"head :"<<head->data<<" Tail :"<<tail->data<<endl;
    operation->deletionAtEnd(head,tail);
    operation->print(head);
    cout<<"head :"<<head->data<<" Tail :"<<tail->data<<endl;
    operation->deleteAtPosition(head,tail,3);
    operation->print(head);
    cout<<"head :"<<head->data<<" Tail :"<<tail->data<<endl;
    return 0;
}