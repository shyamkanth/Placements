#include<iostream>
using namespace std;

int count(int num, int sum){
    if(num==0){
        return sum;
    }
    int rem = num%10;
    if(rem==0){
        sum = sum +1;
        return count(num/10, sum);
    }else{
        return count(num/10,sum);
    }
}

int main(){
    cout<<count(24200000,0);
}