#include <iostream>
#include <climits>
using namespace std;

int min(int dist[], bool visited[], int v){
    int min = INT_MAX, min_index;
    for(int i=0;i<v;i++){
        if(!visited[i] && dist[i]<min){
            min = dist[i];
            min_index = i;
        }
    }
    return min_index;
}

void dijkstra(int** graph, int v, int src){
    int* dist = new int[v];
    bool* visited = new bool[v];
    for(int i=0;i<v;i++){
        dist[i] = INT_MAX;
        visited[i] = 0;
    }

    dist[src]=0;
    for(int i=0;i<v-1;i++){
        int vertex = min(dist, visited, v);
        visited[vertex] = true;

        for(int k=0;k<v;k++){
            if(!visited[k] && graph[vertex][k] && dist[vertex]+graph[vertex][k]<dist[k]){
                dist[k] = graph[vertex][k]+dist[vertex];
            }
        }
    }

    cout<<"Vertex \tDistance from source"<<endl;
    for(int i=0;i<v;i++){
        cout<<i<<"\t"<<dist[i]<<endl;
    }
}

int main(){
    int** graph;
    int vertices;
    cout<<"Enter number of vertices : ";
    cin>>vertices;
    graph = new int*[vertices];
    for(int i=0;i<vertices;i++){
        graph[i] = new int[vertices];
    }
    cout<<"Enter adjacency matrix\n";
    for(int i=0;i<vertices;i++){
        for(int j=0;j<vertices;j++){
            cout<<i<<","<<j<<" : ";
            cin>>graph[i][j];
        }
    }
    cout<<"Enter source vertex : ";
    int src;
    cin>>src;

    dijkstra(graph, vertices, src);

    return 0;
}