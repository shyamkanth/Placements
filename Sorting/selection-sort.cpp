#include<iostream>
#include"helper.cpp"

using namespace std;

void selectionSort(int arr[], int size){
    for(int i=0;i<size-1;i++){
        for(int j=i+1;j<size;j++){
            if(arr[i]>arr[j]){
                swap(arr[i],arr[j]);
            }
        }
    }
}

int main()
{
    int arr[]={3,1,5,7,1,2};
    int size = sizeof(arr)/sizeof(arr[0]);
    selectionSort(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}