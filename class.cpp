#include<iostream>

using namespace std;

class Smartphone{
    public:
    string brand;
    int ram;
    int storage;

    void details(string name, int ram, int storage){
        this->brand = name;
        this->ram = ram;
        this->storage = storage;
    }

};

int main()
{
    Smartphone phone1,phone2,phone3;
    phone1.details("Xiomi",4,64);
    phone2.details("Iphone",8,128);
    phone3.details("Samsung",4,64);

    cout<<"Phone 1 Details :"<<endl;
    cout<<"Name : "<<phone1.brand<<endl;
    cout<<"Ram : "<<phone1.ram<<endl;
    cout<<"Storage : "<<phone1.storage<<endl;

    cout<<"Phone 2 Details :"<<endl;
    cout<<"Name : "<<phone2.brand<<endl;
    cout<<"Ram : "<<phone2.ram<<endl;
    cout<<"Storage : "<<phone2.storage<<endl;

    cout<<"Phone 3 Details :"<<endl;
    cout<<"Name : "<<phone3.brand<<endl;
    cout<<"Ram : "<<phone3.ram<<endl;
    cout<<"Storage : "<<phone3.storage<<endl;

    
    return 0;
}