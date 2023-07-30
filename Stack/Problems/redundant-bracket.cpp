// Check redundant brackets in an expression
// Shyam Sunder Kanth
// Insta : still_23.6_8

#include <iostream>
#include <stack>

using namespace std;

bool checkRedundant(string &str)
{
    stack<char> stack;
    for(int i =0;i<str.length();i++){
        int ch = str[i];
        if(ch == '(' || ch == '+'|| ch =='-'||ch=='*'||ch=='/'){
            stack.push(ch);
        }else{
            if(ch == ')'){
                bool isRedundant = true;
                while(stack.top() != '('){
                    char top = stack.top();
                    if(top == '+'||top=='-'||top=='*'||top=='/'){
                        isRedundant = false;
                    }
                    stack.pop();
                }
                if(isRedundant == true){
                    return true;
                }
            }
        }
    }
    return false;
}

int main()
{
    string str = "((a+b))";
    if (checkRedundant(str)){
        cout << "Redundant bracket is present";
    }else{
        cout << "Redundant bracket is not present";
    }
    return 0;
}