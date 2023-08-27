#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reverse(queue<int> &q){
    stack<int> st;
    while(!q.empty()){
        int ele = q.front();
        q.pop();
        st.push(ele);
    }

    while(!st.empty()){
        int ele = st.top();
        st.pop();
        q.push(ele);
        cout<<ele<<" ";
    }
    cout<<endl;
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverse(q);

    cout<<q.front()<<endl;
    cout<<q.back();

    


}