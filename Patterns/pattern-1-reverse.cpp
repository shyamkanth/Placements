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
    for(int i=row;i>0;i--){
        for(int j=row;j>=i;j--){
            cout<<"* ";
        }
        cout<<"\n";
    }
    return 0;
}