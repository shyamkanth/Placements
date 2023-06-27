#include<iostream>

using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data){
        this->data = data;
        this->next = NULL;
    }

};

int main()
{
    Node* tail = new Node(10);
    cout<<tail->data;
    return 0;
}