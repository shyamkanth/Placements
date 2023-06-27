// Program to reverse a number using recursion in cpp
// Shyam Sumder Kanth

#include<iostream>
using namespace std;

int Rev(int n,int sum){
    if(n==0){
        return sum;
    }
    int rem = n%10;
    sum = sum * 10 + rem;
    return Rev(n/10, sum);
}

int main(){
    cout<< Rev(1234, 0);
    return 0;

}