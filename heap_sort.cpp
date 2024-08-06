#include <iostream>
using namespace std;


void swap(int *a , int *b){
    int t = *a;
    *a = *b;
    *b = t;
}

void Heapify(int arr[],int i,int size){
    int l = 2*i+1;
    int r = 2*i+2;
    int largest = i;
    if(l<size && arr[l]>arr[largest])
    largest = l;
    if(r<size && arr[r]>arr[largest])
    largest = r;
    if (largest!=i){
        swap(arr[i],arr[largest]);
        Heapify(arr,largest,size);
    }
}

void maxHeap(int arr[],int size){
    for(int i = size/2;i>=0;i--){
        Heapify(arr,i,size);
    }
}

void HeapSort(int arr[],int size){
    maxHeap(arr,size-1);
    for(int i = size-1;i>-1;i--){
        swap(arr[0],arr[i]);
        Heapify(arr,0,i);
    }
}

int main(){
    int arr[]={2,3,1,5,4,8,6,7};
    int size = sizeof(arr)/sizeof(int);
    HeapSort(arr,size);
    for(int i = 0 ; i < size;i++)
    cout<<arr[i]<<" ";
    cout<<endl;
    return 0;
}