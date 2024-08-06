#include <iostream>
#include <queue>
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
    void edge(int start, int end){
        adjmatrix[start][end] = 1;
    }
    void print(){
        for(int i=0;i<vertices;i++){
            for(int j=0;j<vertices;j++){
                cout<<adjmatrix[i][j]<<" ";
            }
            cout<<endl;
        }
    }
    void bfs(int start_vertex){
        queue<int> q;
        bool* visited = new bool[vertices];
        int* distance = new int[vertices];
        int* path = new int[vertices];
        for(int i=0;i<vertices;i++){
            visited[i] = false;
        }
        q.push(start_vertex);
        visited[start_vertex] = true;
        distance[start_vertex] = 0; 
        path[start_vertex] = start_vertex;
        while(!q.empty()){
            int vertex = q.front();
            q.pop();
            for(int i =0;i<vertices;i++){
                if(adjmatrix[vertex][i] && !visited[i]){
                    q.push(i);
                    distance[i] = distance[vertex] +1;
                    path[i]=vertex;
                    visited[i]=true;
                }
            }
            cout<<vertex<<" ";
        }
        cout<<endl;
    }
};

int main(){
    Graph g(8);
    g.edge(0,1);
    
    
    g.bfs(0);
    return 0;
}