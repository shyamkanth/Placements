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

// isCircular function
bool isCircular(Node* tail){
        if(tail == NULL){
            return true;
        }
        Node* temp = tail->next;
        while(temp != NULL && temp != tail){
            temp = temp->next;
        }
        if(temp == tail){
            return true;
        }
        return false;
}

//Traversing the linked list
void print(Node* head, Node* tail){
        Node* temp = tail;
        do{
            cout<<tail->data<<" ";
            tail = tail->next;
        }while(tail != temp);
        cout<<endl;
    }

//Insertion
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

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertion(tail,1,1);
    print(head,tail);
    insertion(tail,1,2);
    print(head,tail);
    insertion(tail,2,4);
    print(head,tail);
    insertion(tail,2,3);
    print(head,tail);
    if(isCircular(head)){
        cout<<"list is circular";
    }else{
        cout<<"list is not circular";
    }
    return 0;
}