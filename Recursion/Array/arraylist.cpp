// Displaying the index of all occurance of an integer using array list 
// Shyam Sunder Kanth

#include<iostream>
#include<list>
using namespace std;

void ArrayList(int arr[], int index, int key, int size, list<int>& arrlist){
    if(index==size){
        return;
    }
    if(arr[index]==key){
        arrlist.push_back(index);
    }
    
    ArrayList(arr, index+1, key, size, arrlist);
}

int main(){
    int arr[] = {4,3,5,7,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 3;
    list<int> arrlist;
    ArrayList(arr,0,key,size,arrlist);
    for(auto i:arrlist){
        cout<<i<<" ";
    }
    cout<<"\n";

}