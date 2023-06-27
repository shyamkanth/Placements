// Given an array of integers, print a sum triangle from it such that the first level has all array elements. From then, at each level number of elements is one less than the previous level and elements at the level is be the Sum of consecutive two elements in the previous level. 
// Input : A = {1, 2, 3, 4, 5}
// Output : [48]
//          [20, 28] 
//          [8, 12, 16] 
//          [3, 5, 7, 9] 
//          [1, 2, 3, 4, 5] 

#include<iostream>
using namespace std;

void printTriangle(int arr[], int n){
    if(n<1){
        return;
    }
    int temp[n-1];
    for(int i=0;i<n-1;i++){
        int x = arr[i]+arr[i+1];
        temp[i]=x;
    }
    
    printTriangle(temp,n-1);
    
    for (int i = 0; i < n ; i++)
        {
            if(i == n - 1)
                cout << arr[i] << " ";
            else
            cout << arr[i] << ", ";
        }
        
        cout << endl;


}

int main(){
    int arr[]={1,2,3,4,5};
    int len = sizeof(arr)/sizeof(arr[0]);
    printTriangle(arr,len);
}