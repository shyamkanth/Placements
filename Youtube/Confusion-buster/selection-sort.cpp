// Shyam Sunder Kanth
// Insta : still_23.6_8
//? Selection Sort

#include<iostream>

using namespace std;

int main()
{
    int arr[5] = {55,12,35,47,99};
    int len = sizeof(arr)/ sizeof(arr[0]);

    for(int a = 0;a<len;a++){
        for(int b = a+1;b<len;b++){
            if(arr[b]<arr[a]){
                swap(arr[a],arr[b]);
            }
        }
    }

    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}