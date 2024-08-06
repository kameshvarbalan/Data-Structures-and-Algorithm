#include <iostream>
using namespace std;

class Graph{
    int vertices;
    bool** adjmatrix;

    public:
    Graph(int v){
        vertices = v;
        adjmatrix = new bool*[vertices];
        for(int i=0;i<vertices;i++){
            adjmatrix[i] = new bool[vertices];
            for(int j=0;j<vertices;j++){
                adjmatrix[i][j] = 0;
            }
        }
    }
    void edge(int start, int end, int weight = 1){
        adjmatrix[start][end] = weight;
    }
    void print(){
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                cout<<adjmatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
};

int main(){
    Graph g(3);
    g.edge(0,1);
    g.edge(1,2);
    g.edge(2,0);
    g.print();
    return 0;
}