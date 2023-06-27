#include<iostream>
using namespace std;
int fibo(int n);
int main(){
    int ans;
    ans = fibo(50);
    cout<<ans;
}
int fibo(int n){
    if(n<2)
        return n;
    return (fibo(n-1)+fibo(n-2));
}