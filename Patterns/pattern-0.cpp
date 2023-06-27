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
    int row;
    cout<<"Enter number of rows : ";
    cin>>row;
    for(int i=1;i<=row;i++){
        for(int j=1;j<=row;j++){
            cout<<"* ";
        }
        cout<<"\n";
    }
    return 0;
}