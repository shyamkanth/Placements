// Reverse stack using recursion
// Shyam Sunder Kanth
// Insta : still_23.6_8

#include <iostream>
#include <stack>

using namespace std;

void insertAtBottom(stack<int> &stack, int num)
{
    if (stack.empty())
    {
        stack.push(num);
        return;
    }
    int top = stack.top();
    stack.pop();

    insertAtBottom(stack, num);

    stack.push(top);
}

void reverseStack(stack<int> &stack)
{

    if (stack.empty())
    {
        return;
    }
    int top = stack.top();

    stack.pop();

    reverseStack(stack);

    insertAtBottom(stack, top);
}

int main()
{
    stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);

    reverseStack(stack);

    int size = stack.size();

    cout << "Reversed Stack is" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << stack.top() << endl;
        stack.pop();
    }
    return 0;
}