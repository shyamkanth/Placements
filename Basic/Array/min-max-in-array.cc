// Finding minimum and maximum in an array
// insta : @still_23.6_8

#include<iostream>

using namespace std;

int mininarray(int arr[], int index, int size){
    if(index==size){
        return index;
    }
    int min;
    for(int i=0;i<size-1;i++){
        if(arr[i]<arr[i+1]){
           min = arr[i];
        }
    }
    return min;
}

int maxinarray(int arr[], int index, int size){
    if(index==size){
        return index;
    }
    int max=arr[0];
    for(int i=0;i<size-1;i++){
        if(arr[i]>max){
            max=arr[i];
        }
    }
    return max;
}

int main()
{
    int arr[]={8,6,2,4,1,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    cout<<"Min : ";
    cout<<mininarray(arr,0,size)<<"\n";
    cout<<"Max : ";
    cout<<maxinarray(arr,0,size);
    return 0;
}












