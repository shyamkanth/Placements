#include <iostream>
#include <list>

using namespace std;

void arrlist(int arr[], int key, int index, int size, list<int>& finallist){
    if(index==size){
        return;
    }
    if(arr[index]==key){
        finallist.push_back(index);
    }
    arrlist(arr,key,index+1,size,finallist);
}

int main(){
    int arr[] = {1, 2, 3, 4, 5,3,7,3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 3;
    list<int> finallist;

    arrlist(arr, key, 0, size, finallist);

    for (auto i : finallist) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
