#include <iostream>
using namespace std;

void swap(int *a , int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[],int low, int high){
    int x = arr[high];
    int i = low-1;
    for (int j = low ; j < high ; j++){
        if(arr[j]<x){
            i++;
            swap(arr[i],arr[j]);
        }
    }
    swap(arr[i+1],arr[high]);
    cout<<endl;
    return i+1;
}

void quicksort(int arr[],int p , int r){
    if (p<r){
        int q  = partition(arr,p,r);
        quicksort(arr,p,q-1);
        quicksort(arr,q+1,r);
    }
}

int main(){
    int arr[] = {9,7,5,11,12,2,14,3,10,6};
    int size = sizeof(arr)/sizeof(arr[0]);
    quicksort(arr,0,size-1);
    for(int i = 0 ; i < size ; i++)
    cout<<arr[i]<<" ";
    cout<<endl;

    return 0;
}