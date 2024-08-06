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
    
    int peek()
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

int key(char ch)
{
    if (ch=='a')
    return 2;
    else if(ch=='b')
    return 4;
    else if (ch=='c')
    return 6;
    else if (ch=='d')
    return 1;
    else
    return 0;
}

int evaluate(string exp)
{
    Stack s;
    for(int i = 0 ; i < exp.length() ; i++)
    {
        char ch = exp[i];
        if (isalpha(ch)){
            int t = key(ch);
            s.push(t);
        }
        else{
            int a = s.peek(); s.pop(); 
            int b = s.peek(); s.pop();
            switch(ch){
                case '+':
                s.push(a+b);
                break;
                case '-':
                s.push(a-b);
                break;
                case '*':
                s.push(a*b);
                break;
                case '/':
                s.push(a/b);
                break;
                case '^':
                s.push(a^b);
                break;  
            }
        }
    }
    return s.peek();
}

string reverse(string exp){
    string rev = "";
    for (int i = 0 ; i < exp.length() ; i++){
        rev = exp[i] + rev;
    }
    cout << rev << endl;
    return rev;
}

int main()
{
    string exp = "+*b+/cad/-cad";
    cout << evaluate(reverse(exp)) <<"\n" <<endl;
    return 0;
}