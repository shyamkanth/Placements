// Shyam Sunder Kanth
// Insta : still_23.6_8
// Stack Linked List implementation

#include<iostream>

using namespace std;

class Stack{
    public:
    int data;
    Stack *next;

    Stack(int data){
        this->data = data;
        this->next = NULL;
    }
};

// Function
void push(Stack* &head, Stack* &tail, int data){
    // Step 1: Creation of new Node
    Stack* newNode = new Stack(data);

    // Step 2: Handle empty list case
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    // Step 3:Handle non empty list case
    tail->next = newNode;
    tail = newNode;
}

void pop(Stack* &head, Stack* &tail){
    // Step 1: Handle empty list case
    if(head == NULL && tail == NULL){
        cout<<"Stack underflow"<<endl;
        return;
    }

    // // Step 2 : handle single node case
    if(head == tail){
        head = NULL;
        tail = NULL;
        return;
    }

    // Step 3: Handle more than one node case
    Stack* temp = head;
    while(temp->next != tail){
        temp = temp->next;
    }
    tail = temp;
    tail->next = NULL;
}

int size(Stack* head){
    if(head == NULL){
        return 0;
    }
    Stack* temp = head;
    int cnt = 0;
    while(temp != NULL){
        temp = temp->next;
        cnt++;
    }
    return cnt;
}

int peek(Stack* head, Stack* tail){
    if(head == NULL){
        cout<<"Stack is empty";
        return -1;
    }
    return tail->data;
}

bool empty(Stack* head){
    if(head == NULL){
        return true;
    }else{
        return false;
    }
}

int main()
{
    Stack* head = NULL;
    Stack* tail = NULL;

    push(head,tail,4);
    push(head,tail,5);
    push(head,tail,6);

    pop(head,tail);
    pop(head,tail);
    pop(head,tail);

    cout<<"Top : "<<peek(head,tail)<<endl;
    cout<<"Size: "<<size(head)<<endl;

    cout<<"isEmpty : "<<empty(head)<<endl;

    return 0;
}