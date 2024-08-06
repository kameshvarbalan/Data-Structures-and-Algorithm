#include <iostream>
using namespace std;

#define N 100

class Queue{
    private:
    int front , rear;
    int arr[N];

    public:
    Queue(){
        front = -1;
        rear = -1;
    }

    bool isfull()
    {
        if (rear == N-1)
        return true;
        else
        return false;
    }

    bool isempty()
    {
        if (front==-1)
        return true;
        else
        return false;
    }

    void enqueue (int x)
    {
        if(isfull())
        cout <<"Queue is full";
        else if (front == -1)
        front = 0;
        rear++;
        arr[rear] = x;
    }

    void dequeue()
    {
        if(isempty())
        cout << "Queue is empty\n";
        else{
            if (front>=rear){
                front = -1;
                rear = -1;
            }
            else
            front++;
        }
    }

    void disp()
    {
        for (int i = front ; i <= rear ; i++)
        cout <<arr[i] <<" ";
    }
};

int main(){
    Queue q;
    q.enqueue(10);
    q.dequeue();
    q.disp();
    q.enqueue(10);
    q.disp();

    return 0;
}