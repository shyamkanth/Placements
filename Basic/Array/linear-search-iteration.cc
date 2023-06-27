// Linear search in string and array of integers
// Shyam Sunder Kanth
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<cmath>
#include<list>

using namespace std;

int linearsearchInteger(int arr[],int key, int size){
    if(size==0){
        return 0;
    }
    for(int i=0;i<size;i++){
        if(arr[i]==key){
            return i;
        }
    }
    return -1;
}

int linearsearchString(string name, char target){
    if(name.length()==0){
        return -1;
    }
    for(int i=0; i<name.length();i++){
        if(name[i]==target){
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr[]={5,8,4,6,2,4,5,6,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    int key = 14;
    string name = "Shyam";
    char target = 'h';
    cout<<linearsearchString(name,target)<<"\n";
    cout<<linearsearchInteger(arr,key,size);
    return 0;
}