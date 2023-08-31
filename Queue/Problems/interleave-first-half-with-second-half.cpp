// Interleave first half of the queue with second half
// Shyam Sunder Kanth
// Insta : still_23.6_8

#include<iostream>
#include<queue>

using namespace std;

void interleave(queue<int> &q){
    queue<int> nq;
    int size = q.size()/2;
    for(int i=0;i<size;i++){
        int ele = q.front();
        q.pop();
        nq.push(ele);
    }

    while(!nq.empty()){
        q.push(nq.front());
        q.push(q.front());
        nq.pop();
        q.pop();
    }
}

int main()
{
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);
    q.push(6);
    q.push(7);
    q.push(8);

    interleave(q);
    cout<<q.front();

    return 0;
}