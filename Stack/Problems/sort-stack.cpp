// Sort stack using recursion
// Shyam Sunder Kanth
// Insta : still_23.6_8

#include <iostream>
#include <stack>

using namespace std;

void sortInsert(stack<int> &stack, int num)
{
    if (stack.empty() || stack.top() < num)
    {
        stack.push(num);
        return;
    }
    int top = stack.top();
    stack.pop();

    sortInsert(stack, num);

    stack.push(top);
}

void sort(stack<int> &stack)
{
    if (stack.empty())
    {
        return;
    }
    int top = stack.top();
    stack.pop();

    sort(stack);

    sortInsert(stack, top);
}

int main()
{
    stack<int> stack;
    stack.push(3);
    stack.push(1);
    stack.push(8);
    stack.push(5);
    stack.push(4);

    sort(stack);
    int size = stack.size();
    cout << "Sorted stack is" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << stack.top() << endl;
        stack.pop();
    }
    return 0;
}