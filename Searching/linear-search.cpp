#include<iostream>

using namespace std;

int linearSearch(int arr[], int target, int size){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i;
        }
    }
}

int main()
{
    int arr[]={2,1,3,4,5,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 2;
    cout<<linearSearch(arr,target, size);
    return 0;
}