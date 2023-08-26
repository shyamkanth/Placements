#include<iostream>

using namespace std;

class Queue{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Queue(int size){
        this->size = size;
        arr = new int[size];
        front =-1;
        rear = -1;
    }

    void enque(int data){
        if(rear == size-1){
            cout<<"Queue overflow"<<endl;
            return;
        }
        if(front == -1){
            front = rear = 0;
            arr[rear] = data;
            return;
        }
        rear++;
        arr[rear] = data;
    }

    void deque(){
        if(front == -1){
            cout<<"Queue underflow"<<endl;
            return;
        }
        if(front == rear){
            front = rear = -1;
            return;
        }
        front++;
    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        return false;
    }

    int frontEle(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[front];
    }

    int lastEle(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        return arr[rear];
    }

    int length(){
        if(front == -1){
            cout<<"Size is 0"<<endl;
            return -1;
        }
        int cnt = 0;
        for(int i=front;i<=rear;i++){
            cnt++;
        }
        return cnt;
    }

};




int main(){
    Queue q(5);
    q.enque(1);
    q.enque(2);
    q.enque(3);
    q.enque(4);
    q.enque(5);

    cout<<q.length()<<endl;
    cout<<q.frontEle()<<endl;
    cout<<q.lastEle()<<endl;
    cout<<q.isEmpty()<<endl;


    return 0;
}