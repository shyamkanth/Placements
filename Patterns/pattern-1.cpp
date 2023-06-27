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
    int n;
    cout<<"enter number of rows : ";
    cin>>n;
    for(int row=1;row<=n;row++){
        for(int col=n;col>=row;col--){
            cout<<"* ";
        }
        cout<<"\n";
    }
    return 0;
}