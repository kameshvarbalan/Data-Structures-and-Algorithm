#include <iostream>
#include <string>
#define MAX 100
using namespace std;

class Stack
{
    private:
    int top;
    char arr[MAX];

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
    
    void push(char x){
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
    
    char peek()
    {
        if (isempty() == true){
        cout <<"Underflow";}
        else
        return arr[top];
    }
    
    void disp(){
        for(int i = 0; i <= top ; i++)
        cout << arr[i] <<" ";
        cout<<endl;
    }
};

int precedence(char op)
    {
        if (op == '^')
        return 3;
        else if (op == '/' || op =='*')
        return 2;
        else if(op == '+' || op=='-')
        return 1;
        else
        return -1;
    }

string conversion(string exp)
{
    Stack s;
    string postfix = "";
    for(int i = 0 ; i < exp.length() ; i++)
    {
        char ch = exp[i];
        if (isalnum(ch)){
            postfix+=ch;
        }
        else if (ch=='('){
            s.push(ch);
        } 
        else if(ch==')'){
            while (!s.isempty() && s.peek()!='('){
                postfix += s.peek();
                s.pop();
            }
            if (s.peek()=='(')
            s.pop();
        }
        else{
            while (!s.isempty() && precedence(ch)<=precedence(s.peek())){
                postfix+=s.peek();
                s.pop(); 
                }       
            s.push(ch);
        }
    }
    while (!s.isempty()){
        postfix+=s.peek();
        s.pop();
    }

    return postfix;
}

int main()
{
    string expression = "a+b*(c^d-e)^(f+g*h)-i";
    cout << conversion(expression) <<"\n";
    return 0;
}