#include<iostream>
#include<queue>
#include<stack>

using namespace std;

void reverse(queue<int> &q,int n, int k){
    stack<int> st;
    for(int i=0;i<k;i++){
        int ele = q.front();
        st.push(ele);
        q.pop();
    }

    while(!st.empty()){
        int ele = st.top();
        st.pop();
        q.push(ele);
    }

    for(int i =0;i<n-k;i++){
        int ele = q.front();
        q.pop();
        q.push(ele);
    }
}

int main(){
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    reverse(q,5,3);

    cout<<q.front()<<endl;
    cout<<q.back();


}