#include <iostream>
using namespace std;

class Node {
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

class LinkedList{
    private:
    Node* head;

    public:
    LinkedList(){
        head = NULL;
    }

    void insert_beginning(int val){
        Node* newNode = new Node(val);
        newNode->next = head;
        head = newNode;
    }

    //Does not work when position is equal or greater than the size of linked list
    void insert_position_after(int val,int position){
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i =0;i<position-1;i++)
        {
            temp=temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }

    //Does not work when position is equal to 1 and greater than the size of the linked list
    void insert_position_before(int val,int position){
        Node* newNode = new Node(val);
        Node* temp = head;
        for (int i =0;i<position-2;i++)
        {
            temp=temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
    void insert_end(int val){
        Node* newNode = new Node(val);
        Node* temp = head;
        while(temp->next != NULL)
        temp = temp->next;
        temp->next = newNode;
    }

    void delete_beginning(){
        if(head==NULL){
            cout<<"Empty"<<endl;
            return;
        }
        Node* temp = head;
        head = temp->next;
        delete(temp);
    }

    //Works only valid position (i.e) less than or equal to the size of linked list
    void delete_position(int position){
        if(head==NULL){
            cout<<"Empty";
            return;
        }
        Node* temp1 = head;
        for(int i = 0 ; i<position-2;i++){
            temp1 = temp1->next;
        }
        Node* temp = temp1->next;
        temp1->next = temp->next;
        delete(temp);
    }
    
    void delete_end(){
        if(head==NULL){
            cout<<"Empty"<<endl;
            return;
        }
        if(head->next==NULL){
            delete(head);
            head=NULL;
            return;
        }
        Node* temp = head;
        while(temp->next->next!=NULL){
            temp = temp->next;
        }
        delete(temp->next);
        temp->next = NULL;
    }

    //Does not handle empty cases
    void disp(){
        Node* temp  = head;
        while (temp != NULL){
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout <<endl;
    }
};

int main()
{
    LinkedList l;
    l.insert_beginning(5);
    l.insert_beginning(10);
    l.insert_beginning(15);
    l.insert_position_after(20,2);
    l.insert_position_before(25,2);
    l.insert_end(30);
    l.disp();
    l.delete_beginning();
    l.delete_end();
    l.delete_position(2);
    l.disp();
    LinkedList l1;
    l1.insert_beginning(10);
    l1.delete_end();
    l1.insert_beginning(3);
    l1.disp();
    return 0;
}