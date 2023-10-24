// Shyam Sunder Kanth
// Insta : still_23.6_8

#include<iostream>

using namespace std;

void exchange(char &ch1, char &ch2){
    char temp=ch1;
    ch1=ch2;
    ch2=temp;
}

void rev(string &str){
    for(int i=0,j=str.length()-1;i<=j;i++,j--){
        exchange(str[i],str[j]);
    }
}

int main()
{
    string str = "Hello";
    rev(str);
    cout<<str;
    return 0;
}