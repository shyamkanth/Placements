#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<array>
#include<list>

using namespace std;

int fibo(int n){
    if(n<2){
        return n;
    }
    return fibo(n-1) + fibo(n-2);
    cout<<n;
    
}

int main()
{
    cout<<fibo(10);
    return 0;
}