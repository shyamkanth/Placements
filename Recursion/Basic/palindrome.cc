#include<iostream>
using namespace std;
 
int rev(int num, int sum){
    if(num==0){
        return sum;
    }
    int rem = num%10;
    sum = (sum*10)+rem;
    return rev(num/10, sum);
}

int palindrome(int num){
    return num == rev(num,0);
}
int main(){
    cout<<palindrome(121);
}