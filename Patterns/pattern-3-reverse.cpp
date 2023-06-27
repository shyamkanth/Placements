#include<iostream>

using namespace std;

int main()
{
    int rows,count=1;
    cin>>rows;
    for(int i=rows;i>=1;i--){
        for(int j=i;j>=1;j--,count++){
            cout<<count<<" ";
        }
        cout<<endl;
    }
    return 0;
}