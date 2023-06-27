// Remove cycle from linked list
// @still_23.6_8
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

//detect cycle
Node* detectCycle(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* slow = head;
    Node* fast = head;
    while(fast != NULL){
        fast = fast->next;
        if(fast != NULL && fast->next != NULL){
            fast = fast->next;
        }
        slow = slow->next;
        if(slow == fast){
            return slow;
        }
    }
    return NULL;
}

// Get starting node of cycle
Node* getStartingNode(Node* head){
    if(head == NULL){
        return NULL;
    }
    Node* intersection = detectCycle(head);
    Node* slow = head;

    while(slow!=intersection){
        slow = slow->next;
        intersection = intersection->next;
    }
    return slow;
}

// Remove cycle from linked list
void removeCycle(Node* head){
    if(head==NULL){
        return;
    }
    Node* start = getStartingNode(head);
    Node* temp = start;
    while(temp->next != start){
        temp = temp->next;
    }
    temp->next = NULL;
}

//Traversing the linked list
void print(Node* &head, Node* &tail){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<"->";
        temp = temp->next;
    }
    cout<<"NULL"<<endl;
}

//Insertion at end
void insertionAtend(Node* &head, Node* &tail, int data){
    if(head==NULL){
        Node* temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    Node* temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;
    insertionAtend(head,tail,1);
    insertionAtend(head,tail,2);
    insertionAtend(head,tail,3);
    insertionAtend(head,tail,4);
    insertionAtend(head,tail,5);
    tail->next = head->next;
    Node* start = getStartingNode(head);
    removeCycle(head);
    if(detectCycle(head)){
        cout<<"cycle is present at ";
        cout<<start->data;
    }else{
        cout<<"cycle is not present";
    }
    return 0;
}