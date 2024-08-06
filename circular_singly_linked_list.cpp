#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class Circular_Linked_List{
    private:
    Node* tail;

    public:
    Circular_Linked_List(){
        tail = NULL;
    }

    void insert_beginning(int val){
        Node* newNode = new Node(val);
        if (tail==NULL){
            tail = newNode;
            newNode->next=tail;
            return;
        }
        newNode->next = tail->next;
        tail->next = newNode;
    }

    //do not check if the list is empty
    void insert_position(int val,int pos){
        Node* newNode = new Node(val);
        Node* temp = tail;
        for(int i = 0;i<pos-1;i++){
            temp= temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
        if(temp==tail){
            tail=newNode;
        }
    }

    void insert_end(int val){
        Node* newNode = new Node(val);
        newNode->next = tail->next;
        tail->next = newNode;
        tail = newNode;
    }

    //Did not check if list is empty before deleting for all three delete functions

    void delete_beginning(){
        if(tail->next == tail){
            delete tail;
            tail = NULL;
            return;
        }
        Node* temp = tail->next;
        tail->next = temp->next;
        delete(temp);
    }

    //position should be valid
    void delete_position(int pos){
        Node* temp = tail;
        for(int i =0;i<pos-1;i++){
            temp=temp->next;
        }
        Node* temp1 = temp->next;
        temp->next = temp1->next;
        delete(temp1);
    }

    void delete_end(){
        if(tail->next == tail){
            delete tail;
            tail = NULL;
            return;
        }
        Node* temp = tail;
        Node* temp1 = tail;
        while(temp1->next!=tail){
            temp1=temp1->next;
        }
        temp1->next = tail->next;
        tail = temp1;
        delete(temp);
    }

    void disp(){
        Node* temp = tail->next;
        while(temp!=tail){
            cout<<temp->data<<" ";
            temp= temp->next;
        }
        cout<<temp->data<<endl;
    }
};

int main(){
    Circular_Linked_List c;
    c.insert_beginning(5);
    c.insert_end(7);
    c.insert_position(6,2);
    c.disp();
    c.delete_position(2);
    c.delete_beginning();
    c.disp();
    return 0;
}