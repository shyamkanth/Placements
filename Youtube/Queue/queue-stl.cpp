// Shyam Sunder Kanth
// Insta : still_23.6_8
// ? Queue STL implementation

#include<iostream>
#include<queue>

using namespace std;

int main()
{
    queue<int> q;

    q.push(4);
    q.push(8);
    q.push(9);

    q.pop();
    q.pop();


    cout<<q.size()<<endl;
    cout<<q.front()<<endl;
    cout<<q.back()<<endl;

    return 0;
}