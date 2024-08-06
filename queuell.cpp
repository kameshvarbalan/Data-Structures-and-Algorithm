#include <iostream>
using namespace std;

class Queue{
    private:
    struct Node{
        int data;
        Node* link;
    }*front,*rear;

    public:
    Queue(){
        rear = NULL;
        front = NULL;
    }

    void enqueue(int val){
        Node* newNode = new Node;
        newNode->data = val;
        if(front==NULL){
            front = rear = newNode;
            return;
        }
        rear->link = newNode;
        rear = newNode;
    }

    void dequeue(){
        if(front==NULL){
            cout<<"Queue is empty"<<endl;
        }
        else if(front==rear){
            Node* temp = front;
            front=rear=NULL;
            delete(temp);
        }
        else{
            Node* temp = front;
            front = front->link;
            delete temp;
        }
    }

    void disp(){
        Node* temp = front;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->link;
        }
        cout<<endl;
    }
};

int main(){
    Queue q;
    q.enqueue(20);
    q.enqueue(10);
    q.dequeue();
    q.disp();
    return 0;
}