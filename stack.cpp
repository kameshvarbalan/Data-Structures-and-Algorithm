#include <iostream>
using namespace std;

#define MAX 1000

class Stack 
{
    private:
    int arr[MAX];
    int top;
    
    public:
    Stack() {
        top = -1;
    }
    
    bool isfull(){
        if (top == MAX-1)
        return true;
        else
        return false;
    }
    
    bool isempty(){
        if (top == -1)
        return true;
        else
        return false;
    }
    
    void push(int x){
        if (isfull() == true)
        cout <<"Stack is full";
        else{
            top++; arr[top] = x;
        }}
    
    void pop(){
        if (isempty() == true)
        cout<< "Stack is empty";
        else
        top--;
    }    
    
    void peek()
    {
        if (isempty() == true){
        cout <<"Underflow";}
        else
        cout<< arr[top];
    }
    
    void disp(){
        for(int i = 0; i <= top ; i++)
        cout << arr[i] <<" ";
        cout<<endl;
    }
};

int main()
{
    Stack s;
    printf("That's called stack");
    return 0;
}