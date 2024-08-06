#include <iostream>
using namespace std;

void merge(int arr[],int p , int q , int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int  L[n1] , R[n2];
    for(int i = 0 ; i < n1 ; i++)
        L[i] = arr[p+i];
    for(int j = 0 ; j < n2 ; j++)
    R[j]=arr[q+j+1];
    int i = 0,j=0,k=p;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k]=L[i];
            i++;
        }
        else{
            arr[k]=R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k]=L[i];
        i++;k++;
    }
    while(j<n2){
        arr[k]=R[j];
        j++;k++;
    }
}

void mergesort(int arr[],int p , int r){
    if (p<r){
        int q = (p+r)/2;
        mergesort(arr,p,q);
        mergesort(arr,q+1,r);
        merge(arr,p,q,r);
    }
}

int main(){
    int arr[] = {1,4,2,6,3,5,7,8,0,9};
    int size = sizeof(arr)/sizeof(arr[0]);
    mergesort(arr,0,size-1);
    for(int i = 0 ; i < size;i++)
    cout<< arr[i]<<" ";
    cout<<endl;
    return 0;
}