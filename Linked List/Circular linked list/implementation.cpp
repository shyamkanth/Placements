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


    void insertion(Node* &head,int element, int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            newNode->next = newNode;
            return;
        }
        Node* curr = head;
        while(curr->data != element){
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }

    void print(Node* head){
        Node* temp = head;
        do{
            cout<<head->data<<" ";
            head = head->next;
        }while(head != temp);
        cout<<endl;
    }

};


int main()
{
    Node* op;
    Node* head = NULL;
    op->insertion(head,1,3);
    op->insertion(head,3,5);
    op->print(head);
    return 0;
}