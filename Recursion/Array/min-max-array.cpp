// Recursive Programs to find Minimum and Maximum elements of array
// Given an array of integers arr, the task is to find the minimum and maximum element of that array using recursion.

// Examples : 

// Input: arr = {1, 4, 3, -5, -4 8, 6};
// Output: min = -5, max = 8

// Input: arr = {1, 4, 45, 6, 10, -8};
// Output: min = -8, max = 45

#include<iostream>
#include<algorithm>
using namespace std;

int findmin(int arr[],int len){
    if(len==1){
        return arr[0];
    }
    return min(arr[len-1], findmin(arr, len-1));
}
int findmax(int arr[], int len){
    if(len==1){
        return arr[0];
    }
    return max(arr[len-1], findmax(arr, len-1));
}

int main(){
    int arr[] = {1, 4, 3, -5, -4, 8, 6};
    int len = sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<=len-1;i++){
        cout<<arr[i]<<"\n";

    }
    int max,min;
    min=findmin(arr,len);
    cout<<min;
    max = findmax(arr,len);
    cout<<max;
}