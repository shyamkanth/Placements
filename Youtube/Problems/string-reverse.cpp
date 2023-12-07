// Reverse a string
// Shyam Sunder Kanth
// Insta : still_23.6_8

#include<iostream>
#include<algorithm>
#include<stack>

using namespace std;

int main()
{
    string str = "Hello";
    // Way-1 : Using function
    reverse(str.begin(), str.end());

    // Way-2 : Two pointer method
    for(int i =0,j=str.length()-1;i<=j;i++,j--){
        swap(str[i],str[j]);
    }

    // Way -3
    // Using stack
    stack<char> st;
    for(int i=0;i<str.length();i++){
        st.push(str[i]);
    }

    string res = "";

    while(!st.empty()){
        char ch = st.top();
        res = res + ch;
        st.pop();
    }


    cout<<res;

    return 0;
}