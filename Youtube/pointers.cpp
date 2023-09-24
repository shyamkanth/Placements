#include<iostream>

using namespace std;

void increment(int &num){
    num++;
    cout<<"Value of number inside the function: "<<num<<endl;
}

int main()
{
    int a = 5;
    int b = 7;

    increment(a);
    increment(b);

    cout<<"value of a outside function : "<<a<<endl;
    cout<<"value of b outside function : "<<b<<endl;

    int *ptr = &a;
    int *ptr2 = &b;
    int **p2p = &ptr;


    cout<<"a = "<<a<<endl;
    cout<<"b = "<<b<<endl;
    cout<<"Ptr = "<<ptr<<endl;
    cout<<"Ptr2 = "<<ptr2<<endl;
    cout<<"p2p = "<<p2p<<endl;

    cout<<"Value of address stored at ptr = "<<*ptr<<endl;
    cout<<"Value of address stored at ptr2 = "<<*ptr2<<endl;

    cout<<"Value of address stored at p2p = "<<**p2p<<endl;

    return 0;
}