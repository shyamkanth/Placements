#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        this->data = val;
        this->next = NULL;
    }
};

int length(Node* head){
    Node* temp = head;
    int cnt = 1;
    while(temp->next != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

void delFromBeg(Node* &head, Node* &tail){
    // step 1: Handle Empty list case
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    // Step 2: Handle Non empty list case
    Node* temp = head;
    head = head->next;
    temp->next = NULL;
}

void delFromEnd(Node* &head, Node* &tail){
    // Step 1: EMpty list
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    // Step 2: Non-empty list
    Node* temp = head;
    while(temp->next != tail){
        temp = temp->next;
    }
    tail = temp;
    temp->next = NULL;
}

void delFromPos(Node* &head, Node* &tail, int pos){
    // Case 1: handle empty list case
    if(head == NULL){
        cout<<"List is empty"<<endl;
        return;
    }

    // Case 2: Non-empty list handle karo
    // Subcase 1: Deletion from beginning case
    if(pos == 1){
        delFromBeg(head,tail);
        return;
    }

    // Subcase 2: Deletion from end case
    int len = length(head);
    if(pos == len){
        delFromEnd(head,tail);
        return;
    }

    // Subcase 3: Any random position
    Node* curr = head;
    Node* prev = NULL;
    int cnt = 1;
    while(cnt<pos){
        prev = curr;
        curr = curr->next;
        cnt++;
    }
    prev->next = curr->next;
    curr->next = NULL;
}

void insertAtBeginning(Node* &head,Node* &tail, int data){
    // Creation of new Node
    Node* newNode = new Node(data);

    // CHeck if the list is empty
    if(head == NULL){
        head = newNode;
        tail = newNode;
        return;
    }

    newNode->next = head;
    head = newNode;
}

void print(Node* head, Node* tail){
    Node* temp = head;
    while(temp != NULL){
        cout<<temp->data<<" ";
        temp = temp->next;
    }
    cout<<endl;
    cout<<"Head : "<<head->data<<endl;
    cout<<"Tail : "<<tail->data<<endl;
}

int main()
{
    Node* head = NULL;
    Node* tail = NULL;

    insertAtBeginning(head,tail,10);
    insertAtBeginning(head,tail,20);
    insertAtBeginning(head,tail,30);
    insertAtBeginning(head,tail,40);
    insertAtBeginning(head,tail,50);
    insertAtBeginning(head,tail,60);

    delFromPos(head,tail,1);
    delFromPos(head,tail,5);
    delFromPos(head,tail,3);
    cout<<"After Deletion"<<endl;
    print(head,tail);

    return 0;
}