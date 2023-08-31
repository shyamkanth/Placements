// Geeks for geeks : Circular tour
// Shyam Sunder Kanth
// Insta : still_23.6_8

#include<iostream>

using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int tour(petrolPump p[],int n)
{
    int deficit =0;
    int balance =0;
    int start =0;

    for(int i=0;i<n;i++){
        balance += p[i].petrol - p[i].distance;
        if(balance<0){
            deficit+=balance;
            balance =0;
            start = i+1;
        }
    }

    if(deficit+balance >=0){
        return start;
    }else{
        return -1;
    }
}

int main()
{
    struct petrolPump p[] = {
        {4,6},{6,5},{7,3},{4,5}
    };
    int num =4;

    int start = tour(p, num);
    cout<<start;
    return 0;
}