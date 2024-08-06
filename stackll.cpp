#include <iostream>
using namespace std;

class Stack{
    private:
    struct Node{
        int data;
        Node* link;
    }*top;

    public:
    Stack(){
        top = NULL;
    }

    void push(int val){
        Node *temp = new Node;
        temp->data = val;
        temp->link = top;
        top = temp;
    }

    void pop(){
        if(top==NULL){
            cout<<"Stack is empty"<<endl;
            return;
        }
        Node* temp = top;
        top = top->link;
        delete temp;
    }

    void disp(){
        Node* temp = top;
        while(temp!=NULL){
            cout<<temp->data<<" ";
            temp = temp->link;
        }
        cout<<endl;
    }

    ~Stack(){
        if(top==NULL)
        return;

        Node* temp;
        while(top!=NULL){
            temp = top;
            top=top->link;
            delete temp;
        }
    }
};

int main(){
    Stack s;
    s.push(10);
    s.push(20);
    s.pop();
    s.disp();
    return 0;
}