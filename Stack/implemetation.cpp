#include <iostream>
#include <stack>

using namespace std;

int main()
{
    stack<int> s;
    s.push(5);
    s.push(10);
    s.push(15);
    int size = s.size();
    for (int i = 0; i < size; i++)
    {
        cout << s.top() << " ";
        s.pop();
    }
    return 0;
}