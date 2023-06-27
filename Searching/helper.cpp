//Swap function
void swap(int &i, int &j){
    int temp = i;
    i = j;
    j = temp;
}

//Sorting function (Quick Sort)
int partition(int arr[], int s, int e){
    int pivot = arr[s];
    int count =0;
    for(int i=s+1;i<=e;i++){
        if(arr[i]<pivot){
            count++;
        }
    }
    int pivotIndex = s + count;
    swap(arr[pivotIndex],arr[s]);
    int i=s;
    int j=e;
    while(i<pivotIndex && j>pivotIndex){
        while(arr[i]<arr[pivotIndex]){
            i++;
        }
        while(arr[j]>arr[pivotIndex]){
            j--;
        }
        if(i<pivotIndex && j>pivotIndex){
            swap(arr[i++], arr[j++]);
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


//Searching function (Binary search)
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

//Searching function (Linear Search)
int linearSearch(int arr[], int target, int size){
    for(int i=0;i<size;i++){
        if(arr[i]==target){
            return i;
        }
    }
}