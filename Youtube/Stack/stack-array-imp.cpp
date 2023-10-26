// Shyam Sunder Kanth
// Insta : still_23.6_8
// Array Implemetation of stack

#include<iostream>

using namespace std;

class Stack{
    public:
    int *arr;
    int size;
    int top;

    Stack(int size){
        this->size = size;
        arr = new int[size];
        top = -1;
    }

    void push(int ele){
        // Handle stack overflow condition
        if(size-top <=1){
            cout<<"Stack overflow";
            return;
        }

        // Handle non s-o condition
        top++;
        arr[top] = ele;
    }

    void pop(){
        // Stack underflow condition
        if(top == -1){
            cout<<"stack underflow";
            return;
        }

        // Non s-u condition
        top--;
    }

    int peek(){
        // Handle empty stack condition
        if(top == -1){
            cout<<"Stack is empty";
            return -1;
        }
        
        // Non-empty case
        return arr[top];
    }

    bool isEmpty(){
        if(top == -1){
            return true;
        }else{
            return false;
        }
    }
};

int main()
{
    Stack st(5);

    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);

    st.pop();
    st.pop();
    st.pop();
    st.pop();
    st.pop();

    cout<<st.peek()<<endl;

    cout<<st.isEmpty();

    return 0;
}