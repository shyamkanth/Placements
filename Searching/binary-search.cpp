#include<iostream>

using namespace std;

int binarySearch(int arr[],int target,int s,int e){
    if(s>e){
        return -1;
    }
    int mid=(s+e)/2;
    if(arr[mid]==target){
        return mid;
    }
    if(target>arr[mid]){
        return binarySearch(arr,target,mid+1,e);
    }else{
        return binarySearch(arr,target,s,mid-1);
    }
    return mid;
}

int main()
{
    int arr[]={1,2,3,4,5,6,7,8,9};
    int size=sizeof(arr)/sizeof(arr[0]);
    int target = 9;
    int index = binarySearch(arr,target,0,size-1);
    cout<<index;
    return 0;
}
