// C++ program to check an array if it is sorted or not using recursion
// Shyam sunder Kanth
#include<iostream>
using namespace std;

int check(int arr[], int index, int size){
    if(index==size-1){
        return true;
    }
    return arr[index]<arr[index+1] && check(arr, index+1, size);
}

int main(){
    int arr[]={3,4,5,6,4,7,5};
    int size = sizeof(arr)/sizeof(arr[0]);
    if(check(arr,0,size)){ 
        cout<<"Sorted";
    }else{
        cout<<"Not Sorted";
    }
}
