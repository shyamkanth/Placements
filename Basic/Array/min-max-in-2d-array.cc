#include<iostream>
#include<algorithm>
#include<string>
#include<cmath>
#include<array>
#include<list>

using namespace std;



int main()
{
    int row=3, col=4;
    int arr[][4]={
        {1,2,3,4},{4,5,6},{7,8,9}
    };
    int size = sizeof(arr)/sizeof(arr[0][0]);
    cout<<size<<"\n";
    cout<<sizeof(arr[0][0]);
    
    return 0;
}