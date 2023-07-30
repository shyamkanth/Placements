# Stack

## Definiton
> A linear data structure that follows the LIFO (Last in, first out) principle is a stack. For example, consider a stack of books or plates: the plate or book that was put on the top last is removed first.

>**The insertion or deletion in a stack can only be done from one end only, known as top.**

## C++ header
`#include<stack>`

## Syntax
`stack<data-type> name;`

## Implementation
Three ways to implement stack
- STL implementation
- Array implementation
- Linked list implementation
>Codes for all implementation are written below as well as in implementation folder.

## Operations
A stack can perform following operation :
- Insertion : Insert an element at the top of stack
- Deletion : Remove an element from the top of stack
- Peek : Returns the top element
- Check Empty : Return true if stack is empty
>**Note: Insertion and deletion from stack can only be done from one end, known as top**.

>**Insertion in stack is called Push.**

>**Deletion from stack is called Pop.**

## Methods
Let suppose we have a stack like this
```
#include<iostream>
#include<stack>
using namespace std;
int main(){
    stack<int> st;
}
```
Given are the STL methods used in Stack

### Insertion : Insert an element at the top of stack

`st.push(val);`

### Deletion : Remove an element from the top of stack

`st.pop();`

### Peek : Returns the top element

`st.top();`

### Check empty : Return true if stack is empty

`st.empty();`

## Implentation using array
First create a class named `Stack` and inside that class create one array and two variables, one that holds the value of top and second one is size.
```
int *arr;
int size;
int top;
```
Now create a constructor `Stack(int size)` for initaiizing value when stack is created using object. Here `size` is passed as argument.
```
Stack(int size)
    {
        this->size = size;
        arr = new int[size];
        top = -1;
    }
```
Now create function for each operation

### Insertion
```
void push(int data){
    if (size - top > 1){
        top++;
        arr[top] = data;
    }
    else{
        cout << "stack overflow";
    }
}
```

### Deletion
```
void pop(){
    if (top >= 0){
        top--;
    }
    else{
        cout << "stack underflow";
    }
}
```

### Peek
```
int peek(){
    if (top >= 0){
        return arr[top];
    }
    else{
        cout << "stack is empty" << endl;
        return -1;
    }
}
```
### Check empty
```
bool isEmpty(){
    if (top >= 0){
        return false;
    }
    else{
        return true;
    }
}
```
Now in your `main` function, crate an object `Stack st(5);` . This will create an stack of size 5. Now you are ready to use the functions. For exmaple :
```
st.push(val);
st.pop();
st.top();
st.isEmpty();
```
## Implentation using Linked list
First create a class named `Stack` and inside that class create two variables, one that holds the value of top and second one is pointer to the next node.
```
int data;
Stack *next;
```
Now create a constructor `Stack(int data)` for initaiizing value when stack is created using object. Here `data` is passed as argument.
```
Stack(int data){
    this->data = data;
    this->next = NULL;
}
```
Now create function for each operation

### Insertion
```
void push(Stack *&head, Stack *&tail, int data){
    Stack *newStack = new Stack(data);
    if (head == NULL){
        head = newStack;
        tail = newStack;
        return;
    }
    else{
        tail->next = newStack;
        tail = newStack;
    }
}
```

### Deletion
```
void pop(Stack *&head, Stack *&tail){
    if (head == NULL && tail == NULL){
        cout << "Stack underflow";
        return;
    }
    if (head->next == NULL){
        head = NULL;
        tail = NULL;
        return;
    }
    Stack *temp = head;
    while (temp->next != tail){
        temp = temp->next;
    }
    tail = temp;
    tail->next = NULL;
}
```

### Peek
```
int peek(Stack *head, Stack *tail){
    if (head == NULL && tail == NULL){
        cout << "Stack is empty" << endl;
        return -1;
    }
    return tail->data;
}
```
### Check empty
```
bool isEmpty(Stack *head){
    if (head == NULL){
        return true;
    }
    else{
        return false;
    }
}
```
### Find length
```
int length(Stack *head){
    int cnt = 1;
    Stack *temp = head;
    while (temp->next != NULL){
        cnt++;
        temp = temp->next;
    }
    return cnt;
}
```
Now in your `main` function, crate two pointer `head` and `tail` and initialize them to NULL. 
```
Stack *head = NULL;
Stack *tail = NULL;
```
Now you are ready to use the functions. For exmaple :
```
push(head, tail, data);
pop(head,tail);
peek(head,tail);
isEmpty(head);
```

### To view problems on stack, navigate to problems folder. Thank you.