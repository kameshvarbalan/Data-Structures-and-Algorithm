#include <iostream>
using namespace std;
#define N 10

class Deque{
    private:
    int front , rear;
    int arr[N];

    public:
    Deque(){
        front = -1;
        rear = -1;
    }

    bool isfull(){
        if ((front == 0 && rear == N-1)|| (front == rear+1))
        return true;
        else
        return false;
    }

    bool isempty(){
        if(front ==-1)
        return true;
        else
        return false;
    }

    void insert_front(int x){
        if (isfull()){
            cout << "List is full";
            return;
        }
        if (front == -1){
            front = 0;
            rear = 0;
        }
        else if(front == 0){
            front = N-1;
        }
        else
        front = front-1;
        arr[front]=x;
    }

    void insert_rear(int x){
        if(isfull()){
            cout<<"List is full";
            return;
        }
        if (front ==-1)
        {
            front = 0 ;rear= 0;
        }
        else if(rear==N-1)
        rear = 0;
        else{
        rear = rear +1;}
        arr[rear]=x;
    }

    void delete_front(){
        if(isempty()){
            cout<<"List is empty";
            return;
        }
        if (front == rear){
            front = -1; rear = -1;
        }
        else if(front == N-1){
            front = 0;
        }
        else 
        front++;
    }

    void delete_rear(){
        if(isempty()){
            cout<<"List is empty";
            return;
        }
        if (front == rear){
            front = -1;rear =-1;
        }
        else if(rear ==0)
        rear = N-1;
        else
        rear--;
    }

    void disp(){
        if (isempty()){
            return;
        }
        for(int i = front ; i<=rear;i++){
            cout<< arr[i] <<" ";
        }
        cout<<endl;
    }
};

int main()
{
    Deque q;
    q.insert_front(1);
    q.insert_rear(10);
    q.disp();
    q.delete_front();
    q.disp();
}