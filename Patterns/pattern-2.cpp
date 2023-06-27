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
    int rows;
    cin>>rows;
    int count=1;
    for(int i=1; i<=rows;i++){
        for(int j=1;j<=rows;j++,count++){
            cout<<count<<" ";
        }
        cout<<"\n";
    }
    return 0;
}