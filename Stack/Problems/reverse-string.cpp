// Reverse string using stack
// Shyam Sunder Kanth
// Insta : still_23.6_8

#include <iostream>
#include <stack>

using namespace std;

int main()
{
    string str = "Hello";
    stack<char> stack;
    for (int i = 0; i < str.length(); i++)
    {
        stack.push(str[i]);
    }
    for (int i = 0; i < str.length(); i++)
    {
        cout << stack.top();
        stack.pop();
    }
    return 0;
}