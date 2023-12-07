// Shyam Sunder Kanth
// Insta : still_23.6_8
// ?Bubble sort

#include<iostream>

using namespace std;

int main()
{
    int arr[5] = {5,4,3,2,1};
    int len = sizeof(arr)/sizeof(arr[0]);

    int cnt = 1;
    while(cnt<len){
        for(int i =0;i<len-cnt;i++){
            if(arr[i]>arr[i+1]){
                swap(arr[i],arr[i+1]);
            }
        }
        cnt++;
    }

    for(int i=0;i<len;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}