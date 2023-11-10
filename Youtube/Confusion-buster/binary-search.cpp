// Shyam Sunder Kanth
// Insta : still_23.6_8
// ? Binary Search

#include<iostream>

using namespace std;

int binarySearch(int arr[], int target, int start, int end){
    if(start>end){
        return -1;
    }

    int mid = (start+end)/2;

    if(target == arr[mid]){
        return mid;
    }

    if(target > arr[mid]){
        return binarySearch(arr,target,mid+1,end);
    }

    if(target < arr[mid]){
        return binarySearch(arr,target, start, mid-1);
    }

    return -1;
}

int main()
{
    int arr[5] = {4,8,9,12,45};
    int len = sizeof(arr)/sizeof(arr[0]);
    int target = 10;

    int res = binarySearch(arr,target,0,len-1);

    if(res == -1){
        cout<<"Element not found";
    }else{
        cout<<target<<" is found at position "<<res+1<<endl;
    }
    return 0;
}