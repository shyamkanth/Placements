#include <iostream>

using namespace std;

// Implementation of node
class Node {
public:
  int data;
  Node *next;

    // Constructor
  Node(int data) {
    this->data = data;
    this->next = NULL;
  }

    // Destructor
  ~Node() {
    int value = this->data;
    if (this->next != NULL) {
      delete next;
      this->next = NULL;
    }
  }
};

Node *removeDuplicates(Node *head) {
  if (head == NULL) {
    return NULL;
  }

  Node* current = head;
  while (current != NULL) {
    Node* prev = current;
    Node* next = current->next;

    // Check for duplicates at the beginning
    while (next != NULL && next->data == current->data) {
      prev->next = next->next;
      next->next = NULL;
      delete next;
      next = prev->next;
    }

    // Check for duplicates after the beginning
    while (next != NULL) {
      if (next->data == current->data) {
        prev->next = next->next;
        next->next = NULL;
        delete next;
        next = prev->next;
      } else {
        prev = next;
        next = next->next;
      }
    }
    current = current->next;
  }
  return head;
}


// Traversing the linked list
void print(Node *head) {
  Node *temp = head;
  while (temp != NULL) {
    cout << temp->data << "->";
    temp = temp->next;
  }
  cout << "NULL" << endl;
}

// Insertion at end
void insertionAtend(Node *&head, Node *&tail, int data) {
  if (head == NULL) {
    Node *temp = new Node(data);
    head = temp;
    tail = temp;
    return;
  }
  Node *temp = new Node(data);
  tail->next = temp;
  tail = temp;
}

int main() {
  Node *head = NULL;
  Node *tail = NULL;
  insertionAtend(head, tail, 2);
  insertionAtend(head, tail, 5);
  insertionAtend(head, tail, 3);
  insertionAtend(head, tail, 2);
  insertionAtend(head, tail, 5);
  print(head);
  head = removeDuplicates(head);
  print(head);
  return 0;
}
