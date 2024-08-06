#include <iostream>
using namespace std;
#define MAX 100


//creating node of a binary tree
class Node {
public:
    char data;
    Node* left;
    Node* right;

    Node(char data) {
        this->data = data;
        left = right = NULL;
    }
};

//stack for Node data type
class Stack {
private:
    Node* arr[MAX];
    int top;

public:
    Stack() {
        top = -1;
    }

    bool isfull() {
        if (top == MAX - 1)
            return true;
        else
            return false;
    }

    bool isempty() {
        if (top == -1)
            return true;
        else
            return false;
    }

    void push(Node* x) {
        if (isfull() == true)
            cout << "Stack is full";
        else {
            top++;
            arr[top] = x;
        }
    }

    void pop() {
        if (isempty() == true)
            cout << "Stack is empty";
        else
            top--;
    }

    Node* peek() {
        if (isempty() == true) {
            cout << "Underflow";
            return NULL;
        } else
            return arr[top];
    }
};

int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

//function to convert given postfix expression to an expression tree
Node* exp_tree(string exp) {
    Stack s;
    for (int i = 0; i < exp.length(); i++) {
        char ch = exp[i];
        if (isalnum(ch)) {
            Node* temp = new Node(ch);
            s.push(temp);
        } else {
            Node* right = s.peek();
            s.pop();
            Node* left = s.peek();
            s.pop();

            Node* new_node = new Node(ch);
            new_node->left = left;
            new_node->right = right;

            s.push(new_node);
        }
    }
    return s.peek();
}

//inorder traversal of the tree
void inorder(Node* root){
    if(root==NULL)
    return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main() {
    string expression = "ab+cde+**";
    Node* root = exp_tree(expression);
    inorder(root);
    return 0;
}