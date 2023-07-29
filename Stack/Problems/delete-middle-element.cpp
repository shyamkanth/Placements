// Delete middle element from stack
// Shyam Sunder Kanth
// Insta : still_23.6_8

#include <iostream>
#include <stack>

using namespace std;

void deleteMiddle(stack<int> &stack, int size, int count)
{
    if (count == size / 2)
    {
        stack.pop();
        return;
    }
    int num = stack.top();
    stack.pop();

    deleteMiddle(stack, size, count + 1);

    stack.push(num);
}

int main()
{
    stack<int> stack;
    stack.push(1);
    stack.push(2);
    stack.push(3);
    stack.push(4);
    stack.push(5);
    deleteMiddle(stack, 5, 0);
    for (int i = 0; i < 5; i++)
    {
        cout << stack.top() << endl;
        stack.pop();
    }
    return 0;
}