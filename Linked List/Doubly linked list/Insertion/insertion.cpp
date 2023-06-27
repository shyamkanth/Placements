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
    void insertAtBeginning(Node* &head,Node* &tail, int data){
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

    // Insertion at end
    void insertAtEnd(Node* &head, Node* &tail, int data){
        if(tail == NULL){
            Node* temp = new Node(data);
            head = temp;
            tail = temp;
        }else{
        Node* nodeToInsert = new Node(data);
        nodeToInsert->prev = tail;
        tail->next = nodeToInsert;
        tail = nodeToInsert;
        }
    }

    // Insertion at any position
    void insertAtPosition(Node* &head,Node* &tail, int position, int data){
        if(head == NULL){
            Node* temp = new Node(data);
            head = temp;
            tail = temp;
        }else{
            if(position==1){
            insertAtBeginning(head,tail,data);
            return;
            }
            Node* temp = head;
            int cnt = 1;
            while(cnt<position-1){
                temp= temp->next;
                cnt++;
            }
            if(temp->next == NULL){
                insertAtEnd(head,tail,data);
                return;
            }
            Node* nodeToInsert = new Node(data);
            nodeToInsert->next = temp->next;
            nodeToInsert->prev = temp;
            temp->next = nodeToInsert;
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
   
    operation->insertAtPosition(head, tail,1,2);
    operation->insertAtPosition(head, tail,2,4);
    operation->print(head);
    cout<<"head :"<<head->data<<" Tail :"<<tail->data<<endl;
    cout<<"length of list : "<<operation->getLength(head)<<endl;
    return 0;
}