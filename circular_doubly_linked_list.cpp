#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;
    Node(int data){
        this->data = data;
        prev = next = NULL;
    }
};

class Doubly_linked_circular_list{
    private:
    Node* tail;

    public:
    Doubly_linked_circular_list(){
        tail = NULL;
    }

    void insert_beginning(int val){
        Node* newNode = new Node(val);
        if(tail==NULL){
            tail = newNode;
            newNode->next = tail;
            newNode->prev = tail;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
        newNode->next->prev=newNode;
        newNode->prev = tail;
    }

    void insert_position_after(int val,int pos){
        Node* newNode = new Node(val);
        Node* temp1 = tail;
        for (int i =0;i<pos;i++){
            temp1 = temp1->next;
        }
        Node* temp2 = temp1->next;
        newNode->next = temp2;
        newNode->prev=temp1;
        temp1->next = newNode;
        temp2->prev = newNode;
    }

    void insert_position_before(int val,int pos){
        Node* newNode = new Node(val);
        Node* temp1 = tail;
        for (int i =0;i<pos-1;i++){
            temp1 = temp1->next;
        }
        Node* temp2 = temp1->next;
        newNode->next = temp2;
        newNode->prev=temp1;
        temp1->next = newNode;
        temp2->prev = newNode;
    }

    void insert_end(int val){
        Node* newNode = new Node(val);
        newNode->next = tail->next;
        tail->next->prev = newNode;
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }

    //Did not do case when list is empty 

    void delete_beginning(){
        Node* temp = tail->next;
        tail->next = temp->next;
        temp->next->prev=tail;
        delete (temp);
    }

    //position should be a valid number 
    void delete_position(int pos){
        Node* temp = tail;
        for(int i = 0 ; i < pos ; i++){
            temp = temp->next;
        }
        Node* temp1=temp->prev;
        Node* temp2=temp->next;
        temp1->next = temp2;
        temp2->prev = temp1;
        delete(temp);
    }

    void delete_end(){
        Node* temp = tail;
        Node* temp1 = temp->prev;
        temp1->next = tail->next;
        tail->next->prev = temp1;
        tail = temp1;
        delete(temp);
    }

    //Does not check whether the list is empty
    void disp(){
        Node* temp = tail->next;
        while(temp!=tail){
            cout<<temp->data<<" ";
            temp=temp->next;
        }
        cout<<temp->data<<endl;
    }
};

int main(){
    Doubly_linked_circular_list l;
    l.insert_beginning(1);
    l.insert_end(2);
    l.insert_position_after(3,1);
    l.insert_position_before(4,2);
    l.disp();
    l.delete_position(2);
    l.delete_beginning();
    l.delete_end();
    l.disp();
    return 0;
}