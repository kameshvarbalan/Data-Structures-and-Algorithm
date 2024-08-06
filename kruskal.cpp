#include <iostream>
using namespace std;

struct Edge{
    int src, dest, weight;
};

void sortEdges(Edge edges[], int m) {
    for (int i = 0; i < m - 1; i++) {
        for (int j = 0; j < m - i - 1; j++) {
            if (edges[j].weight > edges[j + 1].weight) {
                Edge temp = edges[j];
                edges[j] = edges[j + 1];
                edges[j + 1] = temp;
            }
        }
    }
}

void KruskalMST(Edge edges[], int v, int e){
    sortEdges(edges, e);
    int path[v];
    for(int i=0;i<v;i++){
        path[i]=i;
    }

    Edge mst[v-1];
    int vertices=0, edge = 0;

    while(vertices< v-1 && edge < e){
        Edge new_edge = edges[edge];
        edge++;

        int src = path[new_edge.src];
        int dest = path[new_edge.dest];

        while(src != path[src]){
            src = path[src];
        }
        while(dest != path[dest]){
            dest = path[dest];
        }
        if(src!=dest){
            mst[vertices] = new_edge;
            vertices++;
            path[src] = dest;
        }
    }

    cout<<"\nMinimum Spanning Tree(MST) edges:\n";
    for (int i = 0; i < vertices; i++) {
        cout<<mst[i].src<<" - "<<mst[i].dest<<" : "<<mst[i].weight<<endl;
    }
}

int main(){
    int edge,vertices;

    cout<<"Enter number of vertices : ";
    cin>>vertices;
    cout<<"Enter number of edges : ";
    cin>>edge;

    Edge edges[edge];
    cout<<"Enter source, destinatin and weight of each edge\n";
    for(int i=0;i<edge;i++){
        cin>>edges[i].src>>edges[i].dest>>edges[i].weight;
    }

    KruskalMST(edges, vertices, edge);
    return 0;
}