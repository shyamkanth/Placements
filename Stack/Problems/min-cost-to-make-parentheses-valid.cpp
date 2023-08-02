// Minimum cost to make parentheses valid
// Shyam Sunder Kanth
// Insta : still_23.6_8

#include<iostream>
#include<stack>

using namespace std;

int minCost(string str){
    if(str.length() %2 != 0){
        return -1;
    }
    stack<char> stack;
    int cost = 0;
    for(int i = 0;i<str.length();i++){
        char ch = str[i];
        if(ch == '{'){
            stack.push(ch);
        }else{
            if(!stack.empty() && stack.top() == '{'){
                stack.pop();
            }else{
                stack.push(ch);
            }
        }
    }
    
    int a =0, b =0;
    while (!stack.empty()){
        if(stack.top() == '{'){
            a++;
        }else{
            b++;
        }
        stack.pop();
    }

    cost = (a+1)/2 + (b+1)/2;
    
    return cost;
}

int main()
{
    string str = "{{{{}}";
    int cost = minCost(str);
    if(cost ==0){
        cout<<"String is valid";
    }else{
        cout<<"Minimum cost is : "<<cost<<endl;
    }
    return 0;
}