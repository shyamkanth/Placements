#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<string>
#include<cstdio>
#include<cmath>
#include<list>

using namespace std;

void triangle1(int r, int c){
    if(r==0){
        return;
    }
    if(c<r){
        triangle1(r, c+1);
        cout<<"* ";
    }else{
        triangle1(r-1,0);
        cout<<"\n";
        
    }
}

void triangle2(int r, int c){
    if(r==0){
        return;
    }
    if(c<r){
        cout<<"*";
        triangle2(r,c+1);
    }else{
        cout<<"\n";
        triangle2(r-1,0);
    }
    
}

int main()
{
    triangle2(4,0);
    return 0;
}