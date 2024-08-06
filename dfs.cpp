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
    void DFSvisit(int n, int* path, bool* visit, int& time, int* stime, int* etime) {
    time += 1;
    visit[n] = true;
    stime[n] = time;
    int i;
    for (i = 0; i < vertices; i++) {
        if (!visit[i] && adjmatrix[n][i]) {
            DFSvisit(i, path, visit, time, stime, etime);
            path[i]=n;
        }
    }
    time +=1;
    etime[n] = time;
    cout<<"Visited Vertex "<<n<<endl;
    }
    void DFS(){
        bool* visited = new bool[vertices];
        int* path = new int[vertices];
        int* etime = new int[vertices];
        int* stime = new int[vertices];
        for(int i=0;i<vertices;i++){
            visited[i]=false;
            path[i]=0;
        }
        int time = 0;
        for(int i=0;i<vertices;i++){
            if(!visited[i]){
                DFSvisit(i,path,visited,time,stime,etime);
            }
        }
        cout<<endl;
    }
};

int main(){
    Graph g(8);
    g.edge(0,1);
    g.edge(1,0);
    g.edge(1,3);
    g.edge(3,1);
    g.edge(0,2);
    g.edge(2,0);
    g.edge(3,4);
    g.edge(4,3);
    g.edge(4,5);
    g.edge(5,4);
    g.edge(5,7);
    g.edge(7,5);
    g.edge(4,6);
    g.edge(6,4);
    g.edge(6,7);
    g.edge(7,6);
    g.DFS();
    cout<<endl;
    return 0;
}