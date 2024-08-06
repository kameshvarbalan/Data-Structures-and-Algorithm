#include <iostream>
using namespace std;

#define N 10

class CircularQueue{
    private:
    int front , rear ;
    int arr[N];

    public:
    CircularQueue(){
        front = -1;
        rear = -1;
    }

    bool isfull(){
        if((front == 0  && rear == N-1) || front == rear +1)
        return true;
        else
        return false;
    }

    bool isempty(){
        if(front == -1)
        return true;
        else
        return false;
    }

    void enqueue(int x){
        if (isfull()){
            cout <<"List is full" <<endl; 
            return;
        }
        if (front == -1){
            front = 0;
        }
        rear = (rear +1)%N;
        arr[rear]=x;
    }

    void dequeue(){
        if(isempty()){
            cout<<"List is empty"<<endl;
            return;
        }
        if(front==rear){
            front = -1; rear = -1;
        }
        else
        front = (front+1)%N;
    }
};

int main(){
    CircularQueue q;
    q.enqueue(3);
    q.enqueue(2);
    q.dequeue();
    return 0;
}