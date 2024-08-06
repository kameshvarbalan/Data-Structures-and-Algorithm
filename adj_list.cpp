#include <iostream>
using namespace std;

class Node{
    public:
    int val;
    Node* link;
    Node(int val){
        this->val = val;
        link = NULL;
    }
};

class Graph{
    int vertices;
    Node** adjlist;
    public:
    Graph(int v){
        vertices = v;
        adjlist = new Node*[vertices];
        for(int i=0;i<vertices;i++){
            adjlist[i]=NULL;
        }
    }

    void edge(int start, int end){
        Node* newNode = new Node(end);
        newNode->link = adjlist[start-1];
        adjlist[start-1] = newNode;
    }

    void print(){
        for(int i=0;i<vertices;i++){
            cout<<"Vertex : "<< i+1;
            Node* temp = adjlist[i];
            while(temp != NULL){
                cout<<"->"<<temp->val;
                temp = temp->link;
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(3);
    g.edge(1,2);
    g.edge(2,3);
    g.edge(3,1);
    g.edge(1,3);
    g.edge(3,2);
    g.edge(2,1);
    g.print();
    return 0;
}