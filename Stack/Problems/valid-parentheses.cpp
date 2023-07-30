// Valid Parentheses
// Shyam Sunder Kanth
// Insta : still_23.6_8

#include <iostream>
#include <stack>
#include <string>

using namespace std;

bool validParentheses(stack<int> stack, string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '{' ||
            str[i] == '[' ||
            str[i] == '(')
        {
            stack.push(str[i]);
        }
        else if ((str[i] == '}' && stack.top() == '{') ||
                 (str[i] == ']' && stack.top() == '[') ||
                 (str[i] == ')' && stack.top() == '('))
        {
            stack.pop();
        }
        else
        {
            return false;
        }
    }

    if (stack.empty())
    {
        return true;
    }
    return false;
}

int main()
{
    stack<int> stack;
    string str = "{[}]";

    if (validParentheses(stack, str))
    {
        cout << "valid";
    }
    else
    {
        cout << "Not valid";
    }

    return 0;
}