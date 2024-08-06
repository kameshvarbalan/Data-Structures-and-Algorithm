#include <iostream>
using namespace std;

int assemblyLineScheduling(int *assembly[], int *t[], int e[], int x[], int n){
    int f1[n], f2[n], l[2][n-1];
    f1[0] = e[0]+assembly[0][0];
    f2[0] = e[1]+assembly[1][0];
    for(int i=1;i<n;i++){
        if(f1[i-1]+assembly[0][i] < f2[i-1]+assembly[0][i]+t[1][i-1]){
            l[0][i-1]=0;
        }
        else{
            l[0][i-1]=1;
        }
        if(f2[i-1]+assembly[1][i] < f1[i-1]+assembly[1][i]+t[0][i-1]){
            l[1][i-1]=1;
        }
        else{
            l[1][i-1]=0;
        }
        f1[i]=min(f1[i-1]+assembly[0][i], f2[i-1]+assembly[0][i]+t[1][i-1]);
        f2[i]=min(f2[i-1]+assembly[1][i], f1[i-1]+assembly[1][i]+t[0][i-1]);
    }
    int time = min(x[0]+f1[n-1], x[1]+f2[n-1]);
    int path[n];
    path[n-1] = x[0]+f1[n-1] < x[1]+f2[n-1] ? 0:1;
    for(int i=n-2;i>-1;i--){
        path[i] = l[path[i+1]][i];
    }
    cout<<"\nFastest Path"<<endl;
    for(int i=0;i<n;i++){
        cout<<path[i]+1<<","<<i+1<<" ";
    }
    return time;
}

int main(){
    int n;
    cout<<"Enter number of stations : ";
    cin>>n;
    cout<<"Enter entry times of station 1 and station 2 : ";
    int e[2], x[2];
    cin>>e[0]>>e[1];
    int *station[2];
    int *transfer[2];
    for(int i=0;i<2;i++){
        station[i]=new int[n];
        transfer[i]=new int[n-1];
    }
    cout<<"Enter times of station 1 : ";
    for(int i=0;i<n;i++){
        cin>>station[0][i];
    }
    cout<<"Enter times of station 2 : ";
    for(int i=0;i<n;i++){
        cin>>station[1][i];
    }
    cout<<"Enter transfer values from station 1 : ";
    for(int i=0;i<n-1;i++){
        cin>>transfer[0][i];
    }
    cout<<"Enter transfer values from station 2 : ";
    for(int i=0;i<n-1;i++){
        cin>>transfer[1][i];
    }
    cout<<"Enter exit times of station 1 and station 2 : ";
    cin>>x[0]>>x[1];
    int time = assemblyLineScheduling(station, transfer, e, x, n);
    cout<<"\n\nMinimum Time = "<<time<<endl;
    return 0;
}