#include <iostream>

using namespace std;

class Stack
{
public:
    int data;
    Stack *next;

    Stack(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

void push(Stack *&head, Stack *&tail, int data)
{
    Stack *newStack = new Stack(data);
    if (head == NULL)
    {
        head = newStack;
        tail = newStack;
        return;
    }
    else
    {
        tail->next = newStack;
        tail = newStack;
    }
}

void pop(Stack *&head, Stack *&tail)
{
    if (head == NULL && tail == NULL)
    {
        cout << "Stack underflow";
        return;
    }
    if (head->next == NULL)
    {
        head = NULL;
        tail = NULL;
        return;
    }
    Stack *temp = head;
    while (temp->next != tail)
    {
        temp = temp->next;
    }
    tail = temp;
    tail->next = NULL;
}

int peek(Stack *head, Stack *tail)
{
    if (head == NULL && tail == NULL)
    {
        cout << "Stack is empty" << endl;
        return -1;
    }
    return tail->data;
}

bool isEmpty(Stack *head)
{
    if (head == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int length(Stack *head)
{
    int cnt = 1;
    Stack *temp = head;
    while (temp->next != NULL)
    {
        cnt++;
        temp = temp->next;
    }
    return cnt;
}

int main()
{
    Stack *head = NULL;
    Stack *tail = NULL;
    push(head, tail, 1);
    push(head, tail, 2);
    push(head, tail, 3);
    push(head, tail, 4);
    push(head, tail, 5);
    pop(head, tail);
    cout << peek(head, tail) << endl;
    cout << isEmpty(head);
    return 0;
}