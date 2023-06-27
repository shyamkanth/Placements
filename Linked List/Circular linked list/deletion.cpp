#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;
    // constructor
    Node(int data){
        this->data = data;
        this->next = NULL;
    }
    // Destructor
    ~Node(){
        int value = this->data;
        if(this->next != NULL){
            delete next;
            this->next = NULL;
        }
        cout<<"memory is free for data: "<<value<<endl;
    }

    void deletetion(Node* &tail, int data){
        // if list is empty
        if(tail == NULL){
            cout<<"List is empty.";
            return;
        }else{
            Node* prev = tail;
            Node* curr = prev->next;
            while(curr->data != data){
                prev = curr;
                curr = curr->next;
            }
            // if single node is present
            if(curr==prev){
                tail = NULL;
            }
            // if 2 or more node is present
            if(tail==curr){
                tail= prev;
            }
            prev->next = curr->next;
            curr->next = NULL;
            delete curr;
        }
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
        if(tail==NULL){
            cout<<"list is empty";
            return;
        }
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
    operation->deletetion(tail,4);
    operation->print(tail);
    operation->deletetion(tail,1);
    operation->print(tail);
    operation->deletetion(tail,3);
    operation->print(tail);
    operation->deletetion(tail,2);
    operation->print(tail);
    return 0;
}