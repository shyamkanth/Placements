# Stack

## Definiton
> A linear data structure that follows the LIFO (Last in, first out) principle is a stack. For example, consider a stack of books or plates: the plate or book that was put on the top last is removed first.

>**The insertion or deletion in a stack can only be done from one end only, known as top.**

### C++ header
`#include<stack>`

### Syntax
`stack<data-type> name;`

### Implementation
Three ways to implement stack
- STL implementation
- Array implementation
- Linked list implementation
>Codes for all implementation are written below as well as in implementation folder.

### Operations
A stack can perform following operation :
- Insertion : Insert an element at the top of stack
- Deletion : Remove an element from the top of stack
- Peek : Returns the top element
- Check Empty : Return true if stack is empty
>**Note: Insertion and deletion from stack can only be done from one end, known as top**.

>**Insertion in stack is called Push.**

>**Deletion from stack is called Pop.**

### Methods
Let suppose we have a stack like this
```
#include<stack>
using namespace std;
int main(){
    stack<int> st;
}
```
**Given are the STL methods used in Stack**

>**Insertion : Insert an element at the top of stack** 

`st.push(val);`

>**Deletion : Remove an element from the top of stack**

`st.pop();`

>**Peek : Returns the top element**

`st.top();`

>**Check empty : Return true if stack is empty**

`st.empty();`

