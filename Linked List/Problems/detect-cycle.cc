// Detect cycle in loop (Normal approach)
// Insta : @still_23.6_8
#include<iostream>
#include<map>

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

//detect cycle using map
bool detectCycle(Node* head){
    if(head == NULL){
        return false;
    }
    map<Node*, bool> visited;
    Node* temp = head;
    while(temp!=NULL){
        if(visited[temp]==true){
            return true;
        }
        visited[temp] = true;
        temp =temp->next;
    }
    return false;
}


//Traversing the linked list
void print(Node* &head){
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
    if(detectCycle(head)){
        cout<<"Cycle is present";
    }else{
        cout<<"Cycle is not present";
    }
    return 0;
}