#include <iostream>

using namespace std;

// Implementation of Node
class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

// Traversing the linked list
void print(Node *&head)
{
    Node *temp = head;
    while (temp != NULL)
    {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

// Insertion at end
void insertionAtend(Node *&head, Node *&tail, int data)
{
    if (head == NULL)
    {
        Node *temp = new Node(data);
        head = temp;
        tail = temp;
        return;
    }
    Node *temp = new Node(data);
    tail->next = temp;
    tail = temp;
}

// Reverse LL
Node *reverse(Node *&head)
{
    Node *prev = NULL;
    Node *curr = head;
    Node *next = head->next;

    while (next != NULL)
    {
        curr->next = prev;
        prev = curr;
        curr = next;
        next = next->next;
    }
    curr->next = prev;

    return curr;
}

Node *add(Node *head1, Node *head2)
{
    Node *ansHead = NULL;
    Node *ansTail = NULL;

    head1 = reverse(head1);
    head2 = reverse(head2);

    Node *temp1 = head1;
    Node *temp2 = head2;

    int carry=0, sum, digit;

    while(temp1!=NULL && temp2!=NULL){
        sum = carry + temp1->data + temp2->data;
        digit = sum %10;
        carry = sum /10;
        insertionAtend(ansHead,ansTail,digit);
        temp1 = temp1->next;
        temp2 = temp2->next;
    }

    if(temp1!=NULL){
        sum = carry + temp1->data;
        digit = sum %10;
        carry = sum /10;
        insertionAtend(ansHead,ansTail,digit);
        temp1 = temp1->next;
    }

    if(temp2!=NULL){
        sum = carry + temp2->data;
        digit = sum %10;
        carry = sum /10;
        insertionAtend(ansHead,ansTail,digit);
        temp1 = temp2->next;
    }

    if(carry != 0){
        sum = carry;
        digit = sum %10;
        insertionAtend(ansHead,ansTail,digit);
    }

    return ansHead;
}

int main()
{
    Node *head1 = NULL;
    Node *tail1 = NULL;
    Node *head2 = NULL;
    Node *tail2 = NULL;
    insertionAtend(head1, tail1, 1);
    insertionAtend(head1, tail1, 9);
    insertionAtend(head1, tail1, 3);
    insertionAtend(head1, tail1, 7);
    insertionAtend(head2, tail2, 1);
    insertionAtend(head2, tail2, 2);
    insertionAtend(head2, tail2, 3);
    Node *ans = add(head1, head2);
    ans = reverse(ans);
    print(ans);

    return 0;
}