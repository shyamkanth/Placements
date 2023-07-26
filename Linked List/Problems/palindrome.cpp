#include <iostream>
#include <vector>

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

bool palindrome(Node *head)
{
    vector<int> arr;
    Node *temp = head;
    while (temp != NULL)
    {
        arr.push_back(temp->data);
        temp = temp->next;
    }
    int size = arr.size();
    int mid = size / 2;
    for (int i = 0, j = size - 1; i<mid, j> mid; i++, j--)
    {
        if (arr[i] != arr[j])
        {
            return 0;
        }
    }
    return 1;
}

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

int main()
{
    Node *head = NULL;
    Node *tail = NULL;
    insertionAtend(head, tail, 1);
    insertionAtend(head, tail, 2);
    insertionAtend(head, tail, 3);
    insertionAtend(head, tail, 4);
    insertionAtend(head, tail, 5);
    print(head);
    if (palindrome(head))
    {
        cout << "List is palindrome";
    }
    else
    {
        cout << "List is not palindrome";
    }
    return 0;
}