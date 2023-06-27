#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int data){
        this->data = data;
        this->prev = NULL;
        this->next = NULL;
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

    // Get length of linked list
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
    Node* node1 = new Node(10);
    Node* head = node1;
    Node* operation;
    operation->print(head);
    int length = operation->getLength(head);
    cout<<length;
    return 0;
}