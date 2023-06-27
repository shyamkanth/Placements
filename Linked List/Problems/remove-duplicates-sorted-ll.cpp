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

// Remove duplicated from sorted linked list
Node *removeDuplicates(Node *head) {
  if (head == NULL) {
    return NULL;
  }
  Node *curr = head;
  while (curr->next != NULL) {
    if (curr->data == curr->next->data) {
      Node *nodeToDelete = curr->next;
      curr->next = curr->next->next;
      nodeToDelete->next = NULL;
      delete nodeToDelete;
    } else {
      curr = curr->next;
    }
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
  insertionAtend(head, tail, 1);
  insertionAtend(head, tail, 2);
  insertionAtend(head, tail, 2);
  insertionAtend(head, tail, 2);
  insertionAtend(head, tail, 3);
  insertionAtend(head, tail, 4);
  insertionAtend(head, tail, 4);
  insertionAtend(head, tail, 5);
  print(head);
  head = removeDuplicates(head);
  print(head);
  return 0;
}
