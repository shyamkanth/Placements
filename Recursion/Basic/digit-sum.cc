#include<iostream>
using namespace std;
int digitsum(int n){
    if(n<=1){
        return n;
    }
    int rem = n%10;
    n=n/10;
    return rem+digitsum(n);
}
int main(){
    cout<<digitsum(456789);
    return 0;
}