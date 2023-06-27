// Linear search using recursion
// Shyam Sunder Kanth

#include<list>
#include<iostream>
using namespace std;

bool find(int arr[], int key, int index, int size){
    if(arr[index]==key){
        return true;
    }
    return index<=size && find(arr,key,index+1,size);
}

int LinearSearch(int arr[], int key, int index, int size){
    if(index>=size-1){
        return -1;
    }
    if(key==arr[index]){
        return index;
    }else{
        return LinearSearch(arr,key,index+1,size);
    }
    
}

int main(){
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<find(arr,8,0,size)<<"\n";
    cout<<LinearSearch(arr,8,0,size);
}