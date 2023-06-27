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

    void insertion(Node* &tail, int element, int data){
        // if list is empty
        if(tail==NULL){
            Node* newNode = new Node(data);
            tail = newNode;
            newNode->next = newNode;
        }else{
            // when list is not empty
            
            Node* curr = tail;
            while(curr->data != element){
                curr = curr->next;
            }
            Node* newNode = new Node(data);
            newNode->next = curr->next;
            curr->next = newNode;
        }
    }


    void print(Node* tail){
        Node* temp = tail;
        do{
            cout<<tail->data<<" ";
            tail = tail->next;
        }while(tail != temp);
        cout<<endl;
    }

};

int main()
{
    Node* tail = NULL;
    Node* operation;
    operation->insertion(tail,1,1);
    operation->print(tail);
    operation->insertion(tail,1,2);
    operation->print(tail);
    operation->insertion(tail,2,4);
    operation->print(tail);
    operation->insertion(tail,2,3);
    operation->print(tail);
    return 0;
}