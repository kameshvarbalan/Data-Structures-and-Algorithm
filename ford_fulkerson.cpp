#include <iostream>
#include <stack>
using namespace std;

class Graph{
    int** matrix;
    int vertices, edges;

    public:
    Graph(int v, int e){
        vertices = v;
        edges = e;
        matrix = new int*[vertices];
        for(int i=0; i<vertices; i++){
            matrix[i] = new int[vertices];
            for(int j=0; j<vertices; j++){
                matrix[i][j] = 0;
            }
        }
    }

    void edge(int source, int dest, int weight){
        matrix[source][dest] = weight;
    }

    void print(int** mat){
        for(int i=0; i<vertices; i++){
            for(int j=0; j<vertices; j++){
                cout<<mat[i][j]<<" ";
            }
            cout<<"\n";
        }
        cout<<"\n";
    }

    bool dfs(int** residualGraph, int s, int t, int parent[]){
        bool visited[vertices];
        for(int i=0; i<vertices; i++){
            visited[i] = 0;
        }
        stack<int> stk;
        stk.push(s);
        visited[s] = 1;
        parent[s] = -1;
        while(!stk.empty() && !visited[t]){
            int u = stk.top();
            stk.pop();
            for(int v=0; v<vertices; v++){
                if(visited[v]==false && residualGraph[u][v]>0){
                    stk.push(v);
                    parent[v] = u;
                    visited[v] = true;
                }
            }
        }
        return (visited[t]==true);
    }

    int FordFulkerson(int s, int t){
        int** residualGraph;
        residualGraph = new int*[vertices];
        for(int u=0; u<vertices; u++){
            residualGraph[u] = new int[vertices];
            for(int v=0; v<vertices; v++){
                residualGraph[u][v] = matrix[u][v];
            }
        }
        int parent[vertices];
        int max_flow = 0;
        cout<<"\nAdjacency Matrix\n";
        print(residualGraph);
        while(dfs(residualGraph, s, t, parent)){
            int path_flow = INT_MAX;
            stack<int> path;
            for(int v=t; v!=s; v=parent[v]){
                int u = parent[v];
                path.push(v);
                path_flow = min(path_flow, residualGraph[u][v]);
            }
            path.push(s);
            for(int v=t; v!=s; v=parent[v]){
                int u = parent[v];
                residualGraph[u][v] -= path_flow;
                residualGraph[v][u] += path_flow; 
            }
            max_flow += path_flow;
            cout<<"Path chosen : ";
            while(path.top()!=t){
                cout<<path.top()<<"->";
                path.pop();
            }
            cout<<path.top()<<endl;
            path.pop();
            cout<<"Flow of path = "<<path_flow<<endl;
            cout<<"Residual Graph\n";
            print(residualGraph);
        }
        return max_flow;
    }

};

int main() {
    cout<<"Enter number of vertices : ";
    int v,e;
    cin>>v;
    cout<<"Enter number of edges : ";
    cin>>e;
    Graph g(v,e);
    cout<<"Enter source vertex, destination vertex and capacity of all the edges"<<endl;
    for(int i=0;i<e;i++){
        int src, dest, weight;
        cin>>src>>dest>>weight;
        g.edge(src, dest, weight);
    }
    int source, sink;
    cout<<"Enter source vertex : ";
    cin>>source;
    cout<<"Enter sink vertex : ";
    cin>>sink;
    int ans = g.FordFulkerson(source, sink);
    cout<<"Maximum Flow = "<<ans<<endl;
    return 0;
}