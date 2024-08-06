#include <iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    Node(int val){
        data = val;
        prev = NULL;
        next = NULL;
    }
};

class DoublyLinkedList{
    public:
    Node* head;

    DoublyLinkedList(){
        head = NULL;
    }

    void insert_beginning(int val){
        Node* newNode = new Node(val);
        if(head == NULL){
            head = newNode;
            return;
        }
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }

    //only works when position is less or equal to size of linked list
    void insert_position_after(int val,int pos){
        Node* newNode = new Node(val);
        Node* temp = head;
        while(pos!=1){
            temp=temp->next;
            pos--;
        }
        //insert end
        if(temp->next == NULL){ 
            temp->next=newNode;
            newNode->prev=temp;
        }
        else{
            Node* temp1=temp->next;
            temp->next = newNode;
            newNode->prev=temp;
            newNode->next = temp1;
            temp1->prev=newNode;
        }
    }

    //only valid if pos is equal or lesser than size of linked list
    void insert_position_before(int val,int pos){
        Node* newNode = new Node(val);
        Node* temp = head;
        //insert at beginning
        if(pos==1){
            newNode->next = head;
            head->prev = newNode;
            head = newNode;
            return;
        }
        while(pos>2){
            temp=temp->next;
            pos--;
        }
        Node* temp1 = temp->next;
        temp1->prev = newNode;
        newNode->next = temp1;
        newNode->prev = temp;
        temp->next = newNode;
    }

    void insert_end(int val){
        Node* newNode = new Node(val);
        if (head == NULL){
            head = newNode;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }

    void delete_beginning(){
        if (head == NULL){
            cout<< "Empty list";
            return;
        }
        if(head-> next == NULL){
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        delete (temp);
    }

    //only works for valid position within the range of size of linked list
    void delete_position(int pos){
        Node* temp = head;
        for(int i = 0 ; i < pos-1 ; i++){
            temp = temp->next;
        }
        Node* temp1 = temp->prev;
        Node* temp2 = temp->next;
        temp1->next = temp2;
        temp2->prev=temp1;
        delete(temp);
    }

    void delete_end(){
        if (head == NULL){
            cout<< "Empty list";
            return;
        }
        if(head-> next == NULL){
            delete head;
            head = NULL;
            return;
        }
        Node* temp = head;
        while(temp->next != NULL) {
            temp = temp->next;
        }
        temp->prev->next = NULL;
        delete temp;
    }

    void disp(){
        Node* temp = head;
        while(temp != NULL) {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    DoublyLinkedList dll;
    dll.insert_beginning(1);
    dll.insert_beginning(2);
    dll.insert_end(3);
    dll.insert_position_after(4,2);
    dll.insert_position_before(5,2);
    dll.disp();  
    dll.delete_beginning();
    dll.delete_position(3);
    dll.delete_end();
    dll.disp();  
    return 0;
}    