#include <iostream>
using namespace std;

int max(int arr[],int n){
    int high = arr[0];
    for(int i = 0 ; i <n;i++){
        if (arr[i]>high)
        high = arr[i];
    }
    return high;
}

void countingsort(int arr[],int size)
{
    int m = max(arr,size);
    int c[m+1],b[size];
    for(int i = 0 ; i <=m ; i++)
    c[i]=0;
    for(int i = 0 ; i < size;i++)
    c[arr[i]]+=1;
    for(int i = 1;i<=m;i++)
    c[i]+=c[i-1];
    for(int i =0;i<size;i++){
        b[c[arr[i]]-1]=arr[i];
        c[arr[i]]-=1;
    }
    for(int i = 0; i<size;i++)
    arr[i]=b[i];
}

int main(){
    int arr[] = {2,2,5,3,2,5,6,4,3,1,3,4,5,3,2,3,4,5,3};
    int size = sizeof(arr)/sizeof(arr[0]);
    countingsort(arr,size);
    for(int i = 0 ; i<size ;i++)
    cout <<arr[i]<<" ";
    cout<<endl;
}