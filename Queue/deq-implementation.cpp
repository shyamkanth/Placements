// Doubly ended queue
// Operations :pushFront, pushBack, popFront, popBack, getFront, getBack, isEmpty, length, print
#include<iostream>

using namespace std;

class Deque{
    public:
    int *arr;
    int size;
    int front;
    int rear;

    Deque(int size){
        this->size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushFront(int data){
        if((front==0 && rear == size-1) || (rear == front-1)){
            cout<<"queue overflow"<<endl;
            return;
        }
        if(front == -1){
            front = rear = 0;
            arr[front]=data;
            return;
        }
        if(front==0){
            front = size-1;
            arr[front]=data;
            return;
        }
        front--;
        arr[front] = data;
    }

    void pushBack(int data){
        if((front==0 && rear == size-1) || (rear == front-1)){
            cout<<"Queue overflow"<<endl;
            return;
        }
        if(front ==-1){
            front = rear = 0;
            arr[rear] = data;
            return;
        }
        if(rear == size-1){
            rear = 0;
            arr[rear] = data;
            return;
        }
        rear++;
        arr[rear] = data;
    }

    void popFront(){
        if(front ==-1){
            cout<<"Queue underflow"<<endl;
            return;
        }
        if(front == rear){
            front = rear = -1;
            return;
        }
        if(front == size-1){
            front = 0;
            return;
        }
        front++;
    }

    void popBack(){
        if(front ==-1){
            cout<<"Queue underflow"<<endl;
            return;
        }
        if(front == rear){
            front = rear = -1;
            return;
        }
        if(rear == 0){
            rear = size-1;
            return;
        }
        rear--;
    }

    int getFront(){
        if(front == -1){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        return arr[front];
    }

    int getBack(){
        if(front == -1){
            cout<<"Queue underflow"<<endl;
            return -1;
        }
        return arr[rear];

    }

    bool isEmpty(){
        if(front == -1){
            return true;
        }
        return false;
    }

    int length(){
        if(front == -1){
            cout<<"Queue is empty"<<endl;
            return -1;
        }
        int cnt = 0;
        for(int i =front;i!=rear; i=(i + 1) % size){
            
            cnt++;
        }
        cnt++;
        return cnt;
    }

    void print(){
        if(front == -1){
            cout<<"Queue is empty";
            return;
        }
        for(int i = front; i!=rear; i=(i + 1) % size){
            
            cout<<arr[i]<<" ";
        }
        cout<<arr[rear]<<endl;
    }
};

int main(){
    Deque dq(5);
    dq.pushBack(2);
    dq.pushBack(3);
    dq.pushBack(4);
    dq.pushFront(6);
    dq.pushFront(7);

    dq.popFront();
    dq.popBack();

    dq.pushFront(1);

    dq.print();
    cout<<"Length = "<<dq.length()<<endl;

    cout<<"Front = "<<dq.getFront()<<endl;
    cout<<"Rear = "<<dq.getBack()<<endl;

}