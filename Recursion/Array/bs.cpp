#include<iostream>
#include<array>
using namespace std;
int search(int arr[], int target, int s, int e);
int main(){
    int arr[] = {1,2,3,44,55,66,77};
    int target = 55;
    int size = *(&arr + 1) - arr;
    cout<<search(arr,target,0,size-1);
}
int search(int arr[], int target, int s, int e){
    int m;
    if(s>e){
        return -1;
    }
    m = s + (e-s)/2;
    if(target==arr[m]){
        return m;
    }
    if(target<arr[m]){
        return search(arr,target,s,m-1);
    }
    return search(arr,target,m+1,e);
}