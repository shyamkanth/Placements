// Shyam Sunder Kanth
// Insta : still_23.6_8
//! Linear Search 

#include<iostream>

using namespace std;

int linearSearch(int arr[], int target, int len){
    for(int i=0;i<len;i++){
        if(arr[i] == target){
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[5] = {5,2,7,6,9};
    int target = 11;
    int len = sizeof(arr)/sizeof(arr[0]);
    
    int res = linearSearch(arr,target,len);
    if(res == -1){
        cout<<"Element Not found"<<endl;
    }else{
        cout<<target<<" is found at position "<<res+1<<endl;
    }

    return 0;
}