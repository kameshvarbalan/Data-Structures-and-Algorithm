#include <iostream>
#include <climits>
using namespace std;

int minKey(int* key, bool* mstSet, int v){
    int min =  INT_MAX, min_index;
    for(int i=0;i<v;i++){
        if(!mstSet[i] && key[i]<min){
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMST(int** graph, int* path, int v){
    cout << "Edge \tWeight\n";
    for (int i = 1; i < v; i++) {
        cout<<path[i]<<" - "<<i<<"\t"<<graph[i][path[i]]<<endl;
    }
}

void primMST(int** graph, int v){
    int* path = new int[v];
    int* key = new int[v];
    bool* mstSET = new bool[v];

    for(int i =0;i<v;i++){
        key[i]=INT_MAX;
        mstSET[i] = false;
    }

    key[0]=0;
    path[0] = -1;

    for(int c=0;c<v-1;c++){
        int k = minKey(key,mstSET, v);
        mstSET[k] = true;
        
        for(int i=0;i<v;i++){
            if(graph[k][i] && !mstSET[i] && graph[k][i]<key[i]){
                path[i] = k;
                key[i] = graph[k][i];
            }
        }
    }

    printMST(graph, path, v);
}

int main(){
    int vertex;
    cout<<"Enter number of vertices : ";
    cin>>vertex;

    int** graph;
    graph = new int*[vertex];
    for(int i=0;i<vertex;i++){
        graph[i]=new int[vertex];
    }

    for(int i=0;i<vertex;i++){
        for(int j=0;j<vertex;j++){
            cout<<i<<","<<j<<" : ";
            cin>>graph[i][j];
        }
    }

    primMST(graph,vertex);

    return 0;
}