#include<iostream>
#include"helper.cpp"

using namespace std;

void bubbleSort(int arr[], int size){
    int counter =1;
    while(counter<size){
        for(int i=0;i<size-counter;i++){
            if(arr[i]>arr[i+1]){
            swap(arr[i], arr[i+1]);
            }
        }
    counter++;
    }
}

int main()
{
    int arr[]={5,1,7,2,6,4};
    int size=sizeof(arr)/sizeof(arr[0]);
    bubbleSort(arr,size);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}