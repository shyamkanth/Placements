#include<iostream>
using namespace std;

int DigitProduct(int n){
    if((n%10)==n){
        return n;
    }
    int rem = n%10;
    n = n/10;
    return rem * DigitProduct(n);
}
int main(){
    cout<<DigitProduct(8);
    return 0;
}