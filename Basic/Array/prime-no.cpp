#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cmath>
#include<array>
#include<list>

using namespace std;

int main()
{
    int num;
    cout<<"enter a number : ";
    cin>>num;
    if(num==2){
        cout<<"Prime.";
    }
    int i=2;
    while(i<num){
        if(i%2==0){
            cout<<"not prime";
            break;
        }else{
            cout<<"Prime";
            break;
        }
        i++;
    }
    return 0;
}