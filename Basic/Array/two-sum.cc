// Two sum problem
// Insta : @still_23.6_8

#include<iostream>

using namespace std;

void TwoSum(int arr[], int target, int size, int index){
    if(size>=2 && index<=size-1){
        for(int i=0;i<size-1;i++){
        if((arr[index]+arr[i]==target)){
            if(index!=i){
                cout<<"["<<i<<","<<index<<"]" ;
                break;
            }
        }
    }
    return TwoSum(arr,target,size,index+1);
    }
}


int main()
{
    int arr[]={2,7,11,15};
    int size = sizeof(arr)/sizeof(arr[0]);
    int target = 17;
    TwoSum(arr,target,size,0);
    return 0;
}