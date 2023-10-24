// Shyam Sunder Kanth
// Insta : still_23.6_8
//STL implementation of Stack

#include<iostream>
#include<stack>

using namespace std;

int main()
{
    stack<int> st;

    st.push(1);
    st.push(2);
    st.push(3);

    st.pop();
    st.pop();

    cout<<st.top();


    cout<<st.size();
    
    return 0;
}