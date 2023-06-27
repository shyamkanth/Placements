#include<iostream>

using namespace std;

void swap(int &i, int &j){
    int temp = i;
    i = j;
    j = temp;
}

int partition(int arr[], int s, int e){
    //assuming starting element as pivot element
    int pivot =arr[s];

    // counting the number of element less than pivot
    int count =0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivot){
            count++;
        }
    }

    // finding pivot index
    int pivotIndex = s + count;

    // Placing pivot element at his right place
    swap(arr[s],arr[pivotIndex]);

    //Placing smaller elements left to the pivot element and greater element right to the pivot element
    // Declaring two variable that will point to the the first and last element of array
    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<=pivot){
            i++;
        }
        while(arr[j]>pivot){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i--],arr[j--]);
        }
    }
    return pivotIndex;
    
}

void quickSort(int arr[],int s, int e){

    if(s>e){
        return;
    }
    int pivot = partition(arr,s,e);

    quickSort(arr,s,pivot-1);
    quickSort(arr,pivot+1,e);

}

int main()
{
    int arr[] ={3,1,5,2,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,size-1);
    for(int i=0;i<size;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}