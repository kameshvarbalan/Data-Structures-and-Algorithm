#include <iostream>
#include <climits>
using namespace std;

class Graph{
    int** matrix;
    int vertices;

    public:
    Graph(int v){
        vertices = v;
        matrix = new int*[vertices];
        for(int i=0; i<vertices; i++){
            matrix[i] = new int[vertices];
            for(int j=0; j<vertices; j++){
                if(i==j){
                    matrix[i][j] = 0;
                }
                else{
                    matrix[i][j] = INT_MAX;
                }
            }
        }
    }

    void edge(int source, int dest, int weight){
        matrix[source][dest] = weight;
    }

    void print(){
        cout<<"\n";
        for(int i=0; i<vertices; i++){
            for(int j=0; j<vertices; j++){
                if(matrix[i][j]==INT_MAX){
                    cout<<"inf\t";
                }
                else{
                    cout<<matrix[i][j]<<"\t";
                }
            }
            cout<<endl;
        }
        cout<<"\n";
    }

    void floyd(){
        for(int x=0; x<vertices; x++){
            for(int u=0; u<vertices; u++){
                for(int v=0; v<vertices; v++){
                    if(u!=x && v!=x && matrix[u][x]!=INT_MAX && matrix[x][v]!=INT_MAX){
                        matrix[u][v] = min(matrix[u][v], matrix[u][x]+matrix[x][v]);
                    }
                }
            }
            cout<<"Matrix at iteration "<<x+1;
            print();
        }
    }
};

int main(){
    int vertices, edges;
    cout<<"Enter total vertices : ";
    cin>>vertices;
    cout<<"Enter total edges : ";
    cin>>edges;
    Graph g(vertices);
    cout<<"Enter start vertex, end vertex and weight of each edge"<<endl;
    for(int i=0; i<edges; i++){
        int start, dest, weight;
        cin>>start>>dest>>weight;
        g.edge(start, dest, weight);
    }
    cout<<"\nAdjacency Matrix";
    g.print();
    g.floyd();
    return 0;
}