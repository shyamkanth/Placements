#include<iostream>

using namespace std;


void merge(int arr[], int s, int e){
    //findinf mid
    int mid = (s+e)/2;

    // finding the size of the array
    int size1 = mid-s+1;
    int size2 = e-mid;

    //Cretaing two temproray array
    int arr1[size1];
    int arr2[size2];

    //Copying values of one half in arr1
    int mainArrayIndex = s;
    for(int i=0; i<size1;i++){
        arr1[i] = arr[mainArrayIndex++];
    }

    //Copying values of one half in arr2
    mainArrayIndex = mid+1;
    for(int i=0;i<size2;i++){
        arr2[i]=arr[mainArrayIndex++];
    }

    //Merge two sorted array
    int index1=0;
    int index2=0;
    mainArrayIndex = s;

    while(index1<size1 && index2<size2){
        if(arr1[index1]<arr2[index2]){
            arr[mainArrayIndex++] = arr1[index1++];
        }else{
            arr[mainArrayIndex++] = arr2[index2++];
        }

        //check for both array if they have some extra elements

        while(index1<size1){
            arr[mainArrayIndex++] = arr1[index1++];
        }

        while(index2<size2){
            arr[mainArrayIndex++] = arr2[index2++];
        }
    }

}

void mergeSort(int arr[], int s, int e){
    if(s>=e){
        return;
    }
    int mid = (s+e)/2;

    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,e);
}

int main()
{
    int arr[]={3,1,5,2,7};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergeSort(arr,0,size-1);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}