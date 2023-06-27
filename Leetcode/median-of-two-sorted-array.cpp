#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<array>
#include<list>

using namespace std;

void median(list<int>& arr1, list<int>& arr2){
    arr1.sort();
    arr2.sort();
    arr1.merge(arr2);
    int size=arr1.size();
    if(size%2!=0){
        int mid=(size-1)/2;
        list<int>::iterator it = arr1.begin();
        advance(it,mid);
        float med;
        med= *it;
        cout<<med;
    }else{
        int mid = (size-1)/2;
        list<int>::iterator it = arr1.begin();
        list<int>::iterator st = arr1.begin();
        advance(it,mid);
        advance(st,mid+1);
        float med;
        med = (*it + *st );
        cout<<med/2;
    }
}

int main()
{
    list<int> arr1;
    list<int> arr2;
    arr1={1,2};
    arr2={3,4};
    median(arr1,arr2);
    return 0;
}