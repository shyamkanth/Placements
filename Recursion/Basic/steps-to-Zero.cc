// Count the number of steps to reduce a given number to zero
// Shyam Sunder Kanth

#include<iostream>
using namespace std;

int steps(int n, int c){
    if(n==0){
        return c;
    }
    if((n%2)==0){
        return steps(n/2, c+1);
    }else{
        return steps(n-1, c+1);
    }
}

int main(){
    cout<<steps(8,0);
}